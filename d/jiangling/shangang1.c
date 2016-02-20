//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "山冈");
	set("long", @LONG
这是一片乱石冈子，杂草丛生，荒凉凋敝。山冈附近没人家，离开
大路很远，也没人经过。山腰处有一个小小的圆土丘，上面立了一块石
碑(bei)。
LONG );
	set("exits", ([
		"west"  : __DIR__"shandao5",
	]));
	set("item_desc", ([
		"bei" : "爱女凌霜华之墓\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiangling");
	set("coor/x", -1460);
	set("coor/y", -2050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}