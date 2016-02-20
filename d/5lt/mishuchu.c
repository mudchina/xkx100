// Room: /d/5lt/msoffice.c

inherit ROOM;

void create()
{
	set("short", "秘书处");
	set("long", @LONG
这里是电视台的秘书处，屋内显眼地摆着两张大大的办公桌，桌子
后面坐着两位秘书。别看职位虽小，电视台大大小小的事务基本上都由
她们把持。东面是台长办公室。
LONG);
	set("outdoors", "5lt");
	set("exits", ([
		"up"     : __DIR__"yanboting",
		"down"   : __DIR__"dating",
		"east"   : __DIR__"tzoffice",
	]));
        set("objects", ([
		__DIR__"npc/xueyuan"   : 1,
	        __DIR__"npc/singleblue": 1,
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("coor/x", -185);
	set("coor/y", 30);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
