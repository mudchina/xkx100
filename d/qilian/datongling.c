// Room: /d/qilian/datongling.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "大通岭");
	set("long", @LONG
这里就是大通岭，为贯连南祈连山脉的紧要之处。可见山羊，野兔
奔行其间，据闻此地盛产灵芝。再往上需得渐渐手脚并用。
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : __DIR__"zhutishan",
		"southeast" : __DIR__"bulangpo2",
		"westup"    : __DIR__"niaojutai",
	]));
	set("coor/x", -10000);
	set("coor/y", 3000);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}