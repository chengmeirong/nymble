#ifndef __NYMBLE_USER_H__
#define __NYMBLE_USER_H__

#include "nymble.h"
#include "nymble_user_entry.h"

namespace Nymble {

typedef std::vector<UserEntry*> UserEntries;

class User : public Nymble, public UserEntries
{
  Pseudonym* pseudonym;
  RSA* verify_key_n;
  
  UserEntry* findEntry(u_char* server_id);
  
  public:
    User();
    ~User();
    
    void setPseudonym(Pseudonym* pseudonym);
    Pseudonym* getPseudonym();
    
    void readVerifyKey(char* verify_key_path);

    UserEntry* findOrCreateEntry(u_char* server_id);
};

}

#endif
