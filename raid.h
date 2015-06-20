#ifndef RAID_H
#define RAID_H



class Raid{
    int _raidDisks;
    bool _raidId;


public:
    Raid(int cantDisks, bool raid );
    void pushElement ();
    void delElement(int position);
    void getElement(int position);

};


#endif // RAID_H
