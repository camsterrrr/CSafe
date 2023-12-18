/**
 * 
*/

/* PREPROCESSING STATEMENTS */
#include <openssl/sha.h>
#include <string>

#include "Database.h"

/* START OF DATABASE CLASS IMPLEMENTATION */

/* CONSTRUCTORS */
/**
 * This function serves as the default constructor of the Database class.
*/
Database::Database() {
    (*this).createTimestamp = 0;
    (*this).lastAccessedTimestamp = 0;
    (*this).lastModifiedTimestamp = 0;
    (*this).numReaders = 0;
    (*this).numWriters = 0;
    (*this).fileLocation = "";
    (*this).masterPWHash = "";
}

Database::Database(time_t createTimestamp, time_t lastAccessedTimestamp, time_t lastModifiedTimestamp,
        std::string fileLocation, std::string masterPWHash) {
    (*this).createTimestamp = createTimestamp;
    (*this).lastAccessedTimestamp = lastAccessedTimestamp;
    (*this).lastModifiedTimestamp = lastModifiedTimestamp;
    (*this).numReaders = 0;
    (*this).numWriters = 0;
    (*this).fileLocation = fileLocation;
    (*this).masterPWHash = masterPWHash;
}

/* MEMBER FUNCTIONS */
bool Database::deleteDB(std::string plaintextMasterPW) {
    bool retVal = false;

    if (verifyMasterPW(plaintextMasterPW)) {

        /* delete operation*/

        retVal = true;
    }

    return retVal;
}

bool Database::updateMasterPW(std::string plaintextMasterPW, std::string newMasterPW) {
    bool retVal = false;
    
    if (verifyMasterPW(plaintextMasterPW)) {
        setMasterPWHash(newMasterPW);
        retVal = true;
    }

    return retVal;
}

bool Database::verifyMasterPW(std::string plaintextMasterPW) {
    std::string hashedPlaintextMasterPW = ""; 
    
    /* hashing operation */

    return hashedPlaintextMasterPW == (*this).masterPWHash;
}

int Database::writeDataToFile(std::string writeLocation) {

    return 0;
}

/* GETTERS */
int Database::getNumReaders() { 
    int retVal = (*this).numReaders;
    return retVal;
}
int Database::getNumWriters() {
    int retVal = (*this).numWriters;
    return retVal;
}
time_t Database::getCreateTimestamp() {
    time_t retVal = (*this).createTimestamp;
    return retVal;
}
time_t Database::getLastAccessedTimestamp() {
    time_t retVal = (*this).lastAccessedTimestamp;
    return retVal;
}
time_t Database::getLastModifiedTimestamp() {
    time_t retVal = (*this).lastModifiedTimestamp;
    return retVal;
}
std::string Database::getFileLocation() {
    std::string retVal = (*this).fileLocation;
    return retVal;
}
std::string Database::getMasterPWHash() {
    std::string retVal = (*this).masterPWHash;
    return retVal;
}

/* SETTERS */
void Database::setCreateTimestamp(time_t createTimestamp) { (*this).createTimestamp = createTimestamp; }
void Database::setFileLocation(std::string fileLocation) { (*this).fileLocation = fileLocation; }
void Database::setLastAccessedTimestamp(time_t lastAccessedTimestamp) { (*this).lastAccessedTimestamp = lastAccessedTimestamp; }
void Database::setLastModifiedTimestamp(time_t lastModifiedTimestamp) { (*this).lastModifiedTimestamp = lastModifiedTimestamp; }
void Database::setMasterPWHash(std::string masterPWHash) { (*this).masterPWHash = masterPWHash; }
void Database::setNumReaders(int numReaders) { (*this).numReaders = numReaders; }
void Database::setNumWriters(int numWriters) { (*this).numWriters = numWriters; }

/* END OF DATABASE CLASS IMPLEMENTATION */