// Room: /d/wuxi/qingmingqiao.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "清名桥");
	set("long", @LONG
清名桥是南门外有名的一座古桥，它原名清宁桥，也称清明桥。江
南运河在城中曲曲折折地流淌，又汇到这里的护城河中。桥身用紫褐色
和青黄色的花岗石砌成，站在桥中可眺望南门外的林荫道。
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"north" : __DIR__"southgate",
		"south" : __DIR__"road7",
	]));
	set("no_clean_up", 0);
	set("coor/x", 370);
	set("coor/y", -850);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}