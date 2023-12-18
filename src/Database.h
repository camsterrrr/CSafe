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
        Database(time_t, time_t, time_t, std::string, std::string);
        /* MEMBER FUNCTIONS */
    
        bool deleteDB(std::string);
        bool updateMasterPW(std::string, std::string);
        bool verifyMasterPW(std::string);
        int writeDataToFile(std::string);
        /* LOCKS */
        /* GETTERS */
        int getNumReaders();
        int getNumWriters();
        time_t getCreateTimestamp();
        time_t getLastAccessedTimestamp();
        time_t getLastModifiedTimestamp();
        std::string getFileLocation();
        std::string getMasterPWHash();
        /* SETTERS */
        void setCreateTimestamp(time_t);
        void setFileLocation(std::string);
        void setLastAccessedTimestamp(time_t);
        void setLastModifiedTimestamp(time_t);
        void setMasterPWHash(std::string);
        void setNumReaders(int);
        void setNumWriters(int);

    /* MEMBER VARIABLES */
    private:
        time_t createTimestamp, lastAccessedTimestamp, lastModifiedTimestamp;
        int numReaders, numWriters;
        pthread_mutex_t mutex;
        pthread_cond_t canRead, canWrite;
        std::string fileLocation, masterPWHash, saltVal;

};

#endif

/* END OF DATABASE CLASS */