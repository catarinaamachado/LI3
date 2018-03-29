typedef struct tags * Tags;


int getTagsSize();

int getTagId(Tags tag);
void setTagId(Tags tag, int id);

char * getTagName(Tags tag);
void setTagName(Tags tag, const char * name);


int getTagValue(Tags tag);
void setTagValue(Tags tag, int value);

void incrementTagValue(Tags tag);

void sortTags(GPtrArray * total_tags);

void cleanTags(Tags t);
