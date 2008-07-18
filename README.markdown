Nymble
======

Anonymizing networks such as Tor provide privacy to users by hiding their IP addresses from servers. For example, Tor uses a volunteer network of nodes, which help redirect users' communications thereby making it difficult to infer the users' IP addresses. Unfortunately, some users have abused such networks to deface websites such as Wikipedia. Since servers are unable to block anonymous users, their normal response is to simply block the entire anonymizing network, denying anonymous access to honest and dishonest users alike

Nymble is a credential system that can be used in conjunction with anonymizing networks such as Tor to selectively block anonymous users while maintaining their privacy. Nymble offers the following properties:

  * **Anonymous blacklisting:** A server can block the IP address of a misbehaving user without knowing the identity of the user or his/her IP address.
  * **Privacy:** Honest and misbehaving users both remain anonymous.
  * **Backward anonymity:** The blacklisted user's previous activity remains anonymous/unlinkable, and is refused future connections.
  * **Blacklist-status awareness:** A user is informed that he has been blocked before accessing a website.
  * **Subjective judging:** Since misbehaving users are blocked without compromising their privacy, servers can provide their own definition of "misbehavior".

We hope that Nymble will make anonymizing networks such as Tor more acceptable to servers that are concerned about abuse from a handful of misbehaving users. Indeed, a few bad apples should not spoil the fun for the rest of us!

<http://www.cs.dartmouth.edu/~nymble/>

License
-------

See LICENSE for licensing details.

Compiling
---------

### libnymble-ruby

To compile the ruby bindings for libnymble, you first must generate a Makefile:

    ruby extconf.rb
    
We require OpenSSL >0.9.8 which is not installed by default on Mac OS X. When installed, you can pass the directory to which it is installed as follows:

    ruby extconf.rb --with-ssl-dir=/opt/local

Once you have a Makefile it is all standard from there:

    make

### extension

  1. Download the Gecko SDK from <http://developer.mozilla.org/en/docs/Gecko_SDK> and install it.
  2. Edit the `GECKO_PATH` variable in the Makefile to reflect the location of the Gecko SDK.
  3. Run `make` in the extension directory.
  4. The `build.sh` in the `extension/nymble` directory will make the extension into an XPI that can be installed in Firefox.
