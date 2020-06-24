struct Difficulties
{
    bool    easy;
    bool    normal;
    bool    hard;
    bool    expert;
    bool    expertPlus;
};
struct Items
{
    double  duration;
    int     length;
    int     bombs;
    int     notes;
    int     obstacles;
    double  njs;
    double  njsOffset;
};
struct ItemType
{
    std::unique_ptr<Items>  easy;
    std::unique_ptr<Items>  normal;
    std::unique_ptr<Items>  hard;
    std::unique_ptr<Items>  expert;
    std::unique_ptr<Items>  expertPlus;
};
struct Characteristics
{
    std::string   name;
    ItemType      difficulties;
};
struct Metadata
{
    Difficulties  difficulties;
    int           duration;
    std::vector<Characteristics>  characteristics;
    std::string   songName;
    std::string   songSubName;
    std::string   songAuthorName;
    std::string   levelAuthorName;
    double        bpm;
};
struct Stats
{
    int       downloads;
    int       plays;
    int       downVotes;
    int       upVotes;
    double    heat;
    double    rating;
};
struct Uploader
{
    std::string   _id;
    std::string   username;
};
struct Time
{
};
struct Data
{
    Metadata    metadata;
    Stats       stats;
    std::string description;
    std::unique_ptr<Time> deletedAt;
    std::string _id;
    std::string key;
    std::string name;
    Uploader    uploader;
    std::string uploaded;
    std::string hash;
    std::string directDownload;
    std::string downloadURL;
    std::string coverURL;
};
ThorsAnvil_MakeTrait(Time);
ThorsAnvil_MakeTrait(Difficulties,      easy, normal, hard, expert, expertPlus);
ThorsAnvil_MakeTrait(Items,             duration, length, bombs, notes, obstacles, njs, njsOffset);
ThorsAnvil_MakeTrait(ItemType,          easy, normal, hard, expert, expertPlus);
ThorsAnvil_MakeTrait(Characteristics,   name, difficulties);
ThorsAnvil_MakeTrait(Metadata,          difficulties, duration, characteristics, songName, songSubName, songAuthorName, levelAuthorName, bpm);
ThorsAnvil_MakeTrait(Stats,             downloads, plays, downVotes, upVotes, heat, rating);
ThorsAnvil_MakeTrait(Uploader,          _id, username);
ThorsAnvil_MakeTrait(Data,              metadata, stats, description, deletedAt, _id, key, name, uploader, uploaded, hash, directDownload, downloadURL, coverURL);

