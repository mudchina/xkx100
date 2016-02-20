// Room: /d/yanping/mangdangshan.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "茫荡山");
	set("long", @LONG
茫荡山清凉世界，风物绝佳。步移景异，所见或石壁陡峭、或深谷
悬崖；山涧小溪忽在道旁潺潺低唱，忽而在断崖前跌落为瀑布；那远近
林中不时传出的鸟叫声和那宛啭不绝的蝉鸣更是增添了幽静、深远的感
觉。举目四顾，但见风烟俱静，天山共色，顿觉心胸开阔、神清气爽。
LONG );
	set("exits", ([
		"east" : __DIR__"gubao",
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	set("coor/x", 1480);
	set("coor/y", -6110);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
