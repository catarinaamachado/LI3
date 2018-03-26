typedef struct tags * PtrTags;


int getTagsSize();

int getTagId(PtrTags tag);
void setTagId(PtrTags tag, int id);


char * getTagName(PtrTags tag);
void setTagName(PtrTags tag, const char * name);


int getTagValue(PtrTags tag);
void setTagValue(PtrTags tag, int value);

int incrementTagValue(PtrTags tag);
