// Room: zhengtang.c
#include <ansi.h>
inherit ROOM;
void bt_same(object who,object me);

void create()
{
	set("short", "签押房");
	set("long", @LONG
这里是扬州府的签押房，平常捕头衙役们都在这里等候程大人的传
招。出门的北面就是大堂了，许多人从这里的门前进进出出，大堂上程
大人正在升堂问案。
LONG
	);
	set("exits", ([
		"west" : __DIR__"yamenyuan",
	]));
	set("objects", ([
		__DIR__"task3/shiye": 1,
	]));
	set("coor/x", -19);
	set("coor/y", 1);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
