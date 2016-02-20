// /kaifeng/jieyin.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "接引佛殿");
	set("long", @LONG
接引佛殿向来是开封城内最热闹的地方。谁不想被接引到西方佛地
呢。殿内供奉接引佛像，佛像前供桌上一盏佛门心灯造形奇古，整日长
明，从此殿出去，就能看到开封铁塔了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"road6",
		"east" : __DIR__"tieta",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
