# generate SSL cert

openssl req -x509 -newkey rsa:4096 -keyout key.pem -out rootcert.pem -days 365
