/**
 * 
*/

/* LIBRARIES */
#include <string>
#include <pthread.h>

/* START OF DATABASE CLASS */
#ifndef DATABASE_H
#define DATABASE_H

class Database {
    public:
        /* CONSTRUCTORS*/
        Database();
        Database(long, long, long, std::string, std::string);
        /* MEMBER FUNCTIONS */
    
        bool deleteDB(std::string);
        bool updateMasterPW(std::string, std::string);
        bool verifyMasterPW(std::string);
        int writeDataToFile(std::string);
        /* LOCKS */
        /* GETTERS */
        int getNumReaders();
        int getNumWriters();
        long getCreateTimestamp();
        long getLastAccessedTimestamp();
        long getLastModifiedTimestamp();
        std::string getFileLocation();
        std::string getMasterPWHash();
        /* SETTERS */
        void setCreateTimestamp(long);
        void setFileLocation(std::string);
        void setLastAccessedTimestamp(long);
        void setLastModifiedTimestamp(long);
        void setMasterPWHash(std::string);
        void setNumReaders(int);
        void setNumWriters(int);

    /* MEMBER VARIABLES */
    private:
        long createTimestamp, lastAccessedTimestamp, lastModifiedTimestamp;
        int numReaders, numWriters;
        pthread_mutex_t mutex;
        pthread_cond_t canRead, canWrite;
        std::string fileLocation, masterPWHash, saltVal;

};

#endif

/* END OF DATABASE CLASS */