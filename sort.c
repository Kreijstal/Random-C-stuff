#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define ArrLength(x)  (sizeof(x) / sizeof(x[0])) 
#define getBit(s,x) (s[x/CHAR_BIT]&(1<<(x%CHAR_BIT)))
//C Sort
//Write a sort implementation because yes.
//thank you lpmc

/*char* argv[]={"hi"};
int argc=ArrLength(argv);*/
//Dynamic String Arrays, YAY!
typedef struct {
  void *array;//so this is like an array so we can store arrays
  size_t sizeofThing;
  size_t used, size;
//  Arr():sizeofThing(sizeof(void*))
//  {}
} Arr;

void initArray(Arr *a, size_t initialSize,size_t SIZEOF) {
//    printf("wowowwwwwwowo/n");
  a->sizeofThing=SIZEOF;
  a->array = (void *)malloc(initialSize * a->sizeofThing);
  a->used = 0;
//  printf("hey hey hey");
//  printf("firsteeeeeeeeeeeeeeeee a.used is %d\n",a->used);
  a->size = initialSize;
}

void appendArray(Arr *a,void *elements,size_t length);
void initAppend(Arr *a,char*string){
    size_t length=strlen(string)+1;
    initArray(a,length,sizeof(char));
   // printf("Hello, I'm here: %s, and length is %d\n", string,length);printf("b4 calling appendArray .used is %d\n",a->used);
    appendArray(a,(void*)string, length);
}
void appendArrays(Arr *a,char *string){
    
    size_t length=strlen(string)+1;
//printf("a.used is %d\n",a->used);
appendArray(a,(void*)string, length);
//printf("Hello, I'm here: %s, and length is %d\n", string,length);
}  
void appendArray(Arr *a,void *elements,size_t length){
void *tmpalloc;
//printf("after calling appendarray a.used is %d\n",a->used);
if (a->used+length > a->size) {
a->size=a->used+length*2;
tmpalloc = (void *)realloc(a->array, a->size * a->sizeofThing);
printf("attempted realloc\n");
if(tmpalloc==NULL){
  /*COULD NOT REALLOCATE!!!*/
  printf("realloc FAILED!!!\n");
  }else{
  a->array=tmpalloc;  }
  }
//printf("dumping: elements %s, a.used is %d\n",elements,a->used);
  memcpy(a->array+(a->used*a->sizeofThing),elements,length*a->sizeofThing);
//printf("dumping: a->array %s\n",a->array);

  a->used+=length;
}
void insertArray(Arr *a, void* element) {
void *tmpalloc;
  if (a->used == a->size) {
    a->size=a->size?a->size:a->sizeofThing;
    a->size *= 2;
    tmpalloc = (void *)realloc(a->array, a->size * a->sizeofThing);
    if(tmpalloc==NULL){
  /*COULD NOT REALLOCATE!!!*/
  printf("realloc FAILED!!!");
  }else{
  a->array=tmpalloc;  }
  }
    
  memcpy(a->array+(a->used++*a->sizeofThing),element,a->sizeofThing);

}
void trimArray(Arr *a){//Alright this is when we don't plan to write it anymore, hopefully, to free up a bit of memory
void *tmpalloc;
tmpalloc=(void *)realloc(a->array,a->used*a->sizeofThing);
if(tmpalloc==NULL){
  /*COULD NOT REALLOCATE!!!*/
  printf("realloc FAILED!!!");
  }else{
  a->array=tmpalloc;  }
    
}
void freeArray(Arr *a) {
int i;
for(i=0;i<a->used;i++){free(*(void**)(a->array+(i*a->sizeofThing)));}
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}
int main(int argc,char *argv[]) {

    struct {
        char *randomSource,*sort, *batchSize,*check,*compressProgram,*files0From,*key,*output,*bufferSize,*fieldSeparator,*temporaryDirectory;
        unsigned char _ignoreLeadingBlanks:1, _dictionaryOrder:1, _ignoreCase:1, _generalNumericSort:1, _ignoreNonprinting:1, _monthSort:1, _humanNumericSort:1, _numericSort:1, _randomSort:1, _reverse:1, _versionSort:1, _debug:1, _merge:1, _stable:1, _parallel:1, _unique:1, _zeroTerminated:1, _help:1, _version:1; 
        //18 bytes reduced to 3 bytes, sounds good to me.
    } flags;
printf("sizeof pointer is %d\nsize of flags is %d\nsize of _ignoreLeadingetc is %d\n",sizeof(void*),sizeof(flags),sizeof(flags._ignoreLeadingBlanks));    

/*SANDBOX PLZ DELETE

puts("SANDBOX START\n");
flags.FLAGS=calloc((__LENGTH/CHAR_BIT)+(__LENGTH%CHAR_BIT?1:0),sizeof(char));
printf("CHAR BIT:%d, __LENGTH:%d, __LENGTH/CHAR_BIT:%d\n",CHAR_BIT,__LENGTH,(__LENGTH/CHAR_BIT)+(__LENGTH%CHAR_BIT?1:0));
flags.FLAGS[0]=(char)198;
printf("FLAGS[0]: %hhu",flags.FLAGS[_numericSort/CHAR_BIT]);
printf("FLAGS[0]: %d\n",getBit(flags.FLAGS,_monthSort));
printf("DAMMIT JUST WORK\n");
printf("SANDBOX END\n");/**/
int i,p;
char **parameters,*parameter; 
Arr dynamicString;
//dynamicString=Arr;//"fagets"
initArray(&dynamicString, argc,sizeof(Arr));
printf("DAMMIT JUST WORK");
/*dynamicString.used--;
appendArrays(&dynamicString,",lol, no u");
puts((char *)dynamicString.array);
printf("excuse me");
free(dynamicString.array);*/
printf("DAMMIT JUST WORK");
for( i = 0; i < argc; i++ )
{
    Arr goddamit;
    initAppend(&goddamit,argv[i]);
    printf("%s %p\n",goddamit.array,goddamit);
    insertArray(&dynamicString,&goddamit);
}
//free(goddamit);
//      getchar();
//parameters=(char**)dynamicString.array;
//printf((dynamicString.array));
//printf("Print attempt %s",((Arr*)dynamicString.array)[0].array);
for(i=0;i<dynamicString.used;i++){
    printf("%s", (char*)((Arr*)dynamicString.array)[i].array);
}
        printf( "\nHello World D:\n\n" );
  
  return 0;
}
