// Room: /d/heimuya/dating1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "堂厅");
	set("long", @LONG
这是『日月神教』下第一大堂：风雷堂的大厅，四目望去，满朴素
的，堂梁上有一副联子(vote)。
LONG    );

	set("exits", ([
		"south" : __DIR__"grass2",
		"northdown" : __DIR__"linjxd5",
	]));
 
	set("objects",([
		__DIR__"npc/jiaotu" : 2,
	]));
	set("item_desc", ([
		"vote": "日月神教，文成武德，泽被苍生。\n"
	]) );
//	set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 4030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}