// Room: /d/wuxi/kuaxiqiao.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "跨溪桥");
	set("long", @LONG
跨溪桥俗称西门吊桥，又称梁清桥，桥下的梁溪河曾一度成为无锡
的别称。来自中原及北方的商贾都要从此进出无锡城。而且这也是到无
锡有名的惠山去的路，向西望去，一条大驿道看不到头，路上来来往往
的人络绎不绝，向东是西门梁溪门。
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"east" : __DIR__"westgate",
		"west" : __DIR__"road14",
	]));
	set("no_clean_up", 0);
	set("coor/x", 300);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}