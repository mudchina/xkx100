// Room: /d/heimuya/hua1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "花园");
	set("long", @LONG
这是一个极精致的小花园。园中，红梅绿竹，青松翠柏，布置得颇
具匠心，往西去是一片青草地。
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
	    "west" : __DIR__"grass2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3020);
	set("coor/y", 4020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}