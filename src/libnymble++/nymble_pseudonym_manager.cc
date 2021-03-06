#include "nymble_pseudonym_manager.h"

namespace Nymble {

PseudonymManager::PseudonymManager()
{
  random_bytes(DIGEST_SIZE, &this->nym_key_p);
}

void PseudonymManager::setMacKeyNP(std::string mac_key_np)
{
  this->mac_key_np = mac_key_np;
}

bool PseudonymManager::createPseudonym(std::string user_id, Pseudonym* pseudonym)
{
  HMAC_CTX ctx;
  u_char buffer[DIGEST_SIZE];
  
  HMAC_Init(&ctx, (u_char*)this->nym_key_p.data(), this->nym_key_p.size(), EVP_sha256());
  HMAC_Update(&ctx, (u_char*)user_id.data(), user_id.size());
  HMAC_Update(&ctx, (u_char*)&this->cur_link_window, sizeof(this->cur_link_window));
  HMAC_Final(&ctx, buffer, NULL);
  
  pseudonym->set_nym(buffer, sizeof(buffer));
  
  HMAC_Init(&ctx, (u_char*)this->mac_key_np.data(), this->mac_key_np.size(), EVP_sha256());
  HMAC_Update(&ctx, (u_char*)pseudonym->nym().data(), pseudonym->nym().size());
  HMAC_Update(&ctx, (u_char*)&this->cur_link_window, sizeof(this->cur_link_window));
  HMAC_Final(&ctx, buffer, NULL);
  
  pseudonym->set_mac(buffer, sizeof(buffer));
  
  return true;
}

}; // namespace Nymble
