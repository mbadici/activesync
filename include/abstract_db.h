#ifndef ABSTRACT_DB_H
#define ABSTRACT_DB_H


class abstract_db
{
    public:
        abstract_db();
        virtual ~abstract_db();
        void db_push();
        int db_pull();

    protected:

    private:
};

#endif // ABSTRACT_DB_H
