// Room: /d/kunlun/shankou.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "昆仑山垭口");
	set("long",@long
这是位于两山之间的一个小山口。只见昆仑山脉绵延千里，群山复
叠，山上树木并不多，不时露出光秃秃的山面和石头，山腰以上均为冰
雪覆盖，冰峰雄峙，高插云霄。
long);
	set("exits",([
		"west"      : __DIR__"klshanlu",
		"southeast" : __DIR__"kekexili",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -110000);
	set("coor/y", 30000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}