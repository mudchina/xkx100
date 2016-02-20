// Room: /d/qilian/qilianshan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "祁连山");
	set("long", @LONG
祁连山为南祁连山脉的最高峰，海拔五千二百多米，山势挺拔，为
西北起酒泉，东南至古浪的第一山。山野遍是奇石，为西北一大奇观，
与东南方马鬃山遥对。山中据闻时有仙人据石对弈.
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"southeast" : __DIR__"niaojutai",
		"east"      : __DIR__"mazongshan",
		"west"      : __DIR__"tieshishan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -12000);
	set("coor/y", 3000);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}