// Room: /d/yueyang/feilaizhong.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "飞来钟");
	set("long", @LONG
原为崇胜寺内古钟，杨么起义时以此报警，杨么高举“等贵贱，均
贫富”义旗，劫富济贫，受人民爱戴，便自筹款物铸成一口大钟，深夜
偷运上龙山头，该钟二毁三造，现四千余斤，游人到此，总要击钟吊古，
告慰忠魂。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"northup"   : __DIR__"longsheshan",
		"southdown" : __DIR__"longxianjing",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/bangzhong" : 1,
	]));
	set("coor/x", -1720);
	set("coor/y", 2310);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
