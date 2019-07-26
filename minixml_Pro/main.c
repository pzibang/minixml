#include "mxml.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
 
int main()
{
    FILE *fp;
    mxml_node_t *tree,*node;
	
	printf("Label1.prt\n");
	
	if((fp = fopen("Label1.xml","r")) == NULL)
	{
		printf("The file can not open\n");
		return -1;
	}

	tree = mxmlLoadFile(NULL,fp,MXML_TEXT_CALLBACK);	//加载文件到树结构中
	fclose(fp);
	
	printf("Loop traversal :\n");	//循环遍历
	for(node = mxmlFindElement(tree,tree,NULL,NULL,NULL,MXML_DESCEND);
		node != NULL; node = mxmlFindElement(node,tree,NULL,NULL,NULL,MXML_DESCEND))
	{
			printf("Element name:%s\n",node->value);
			if(strcmp(node->value.opaque,"AreaSize") == 0)
			{
				printf("	Height:%s,Width=%s\n",mxmlElementGetAttr(node,"Height"),mxmlElementGetAttr(node,"Width"));
			}else if(strcmp(node->value.opaque,"ObjectList")==0)
			{
				printf("	count:%s\n",mxmlElementGetAttr(node,"Count"));
			}else if(strcmp(node->value.opaque,"zOrder")==0)
			{
				printf("	zOrder:%d\n",node->child->value.integer);
			}else if(strcmp(node->value.opaque,"Type")==0)
			{
				printf("	Type:%s\n",node->child->value.text.string);
			}else if(strcmp(node->value.opaque,"Start")==0)
			{
				printf("	X=%s,Y=%s,order=%s\n",mxmlElementGetAttr(node,"X"),mxmlElementGetAttr(node,"Y"),mxmlElementGetAttr(node,"order"));
			}else if(strcmp(node->value.opaque,"End")==0)
			{
				printf("	X=%s,Y=%s,order=%s\n",mxmlElementGetAttr(node,"X"),mxmlElementGetAttr(node,"Y"),mxmlElementGetAttr(node,"order"));
			}else if(strcmp(node->value.opaque,"Color")==0)
			{
				printf("	Color:%s\n",node->child->value.text.string);
			}else if(strcmp(node->value.opaque,"PenWidth")==0)
			{
				printf("	PenWidth:%s\n",node->child->value.text.string);
			}else if(strcmp(node->value.opaque,"FillColor")==0)
			{
				printf("	FillColor:%s\n",node->child->value.text.string);
			}else if(strcmp(node->value.opaque,"Name")==0)
			{
				printf("	Name:%s\n",node->child->value.text.string);
			}
	}
 
	printf("\nSearch traversal :\n");
	node = mxmlFindElement(tree,tree,"AreaSize",NULL,NULL,MXML_DESCEND);
	printf("AreaSize:\n	Height=%s,Width=%s\n",mxmlElementGetAttr(node,"Height"),mxmlElementGetAttr(node,"Width"));
	node = mxmlFindElement(tree,tree,"ObjectList",NULL,NULL,MXML_DESCEND);
	printf("	ObjectList:Count:%s\n",mxmlElementGetAttr(node,"Count"));
	node = mxmlFindElement(tree,tree,"zOrder",NULL,NULL,MXML_DESCEND);
	printf("	zOrder:%d\n",node->child->value.integer);
	node = mxmlFindElement(tree,tree,"Type",NULL,NULL,MXML_DESCEND);
	printf("	Type:%s\n",node->child->value.text.string);
	node = mxmlFindElement(tree,tree,"Start",NULL,NULL,MXML_DESCEND);
	printf("	Start:X=%s,Y=%s,order=%s\n",mxmlElementGetAttr(node,"X"),mxmlElementGetAttr(node,"Y"),mxmlElementGetAttr(node,"order"));
	node = mxmlFindElement(tree,tree,"End",NULL,NULL,MXML_DESCEND);
	printf("	End:X=%s,Y=%s,order=%s\n",mxmlElementGetAttr(node,"X"),mxmlElementGetAttr(node,"Y"),mxmlElementGetAttr(node,"order"));
	node = mxmlFindElement(tree,tree,"Color",NULL,NULL,MXML_DESCEND);
	printf("	Color:%s\n",node->child->value.text.string);
	node = mxmlFindElement(tree,tree,"PenWidth",NULL,NULL,MXML_DESCEND);
	printf("	PenWidth=%s\n",node->child->value.text.string);
	node = mxmlFindElement(tree,tree,"FillColor",NULL,NULL,MXML_DESCEND);
	printf("	FillColor:%s\n",node->child->value.text.string);
	node = mxmlFindElement(tree,tree,"Name",NULL,NULL,MXML_DESCEND);
	printf("	Name:%s\n",node->child->value.text.string);
 
	system("pause");
 
    return 0 ;
}