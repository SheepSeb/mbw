

// Function that generates publicKey and privateKey pair

// publicKey               - pointer to buffer to hold the public key
// privateKey              - pointer to buffer to hold the public key
void generateKeys(long int* publicKey, long int* privateKey);


//Function that returns the encrypted message given the key

//key                     -key to encrypt the message with
//message                 -message to be encoded
char* encryptMessageKey(long int key, char* message);

char *encryptRot13(const char *message);
