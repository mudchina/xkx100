// Room: /d/quanzhou/qingyuandong.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "清源洞");
	set("long", @LONG
从虎乳泉往上，就看到一个山门，门上刻着「第一洞天」四个字。
门后有一观空楼，楼宇尽处便是一洞曰「蜕岩」，即清源洞。相传南宋
绍兴有一道人裴姓者追赶一条伤害生灵的大蛇到了这里，那蛇妖钻入石
洞中，裴道人索性就在洞口上坐化了，因而又名「裴仙洞」。据闻此洞
深不可测，可通至洛阳江。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"huruquan",
		"northdown" : __DIR__"shanlu1",
		"westup"    : __DIR__"nantaiyan",
	]));
	set("coor/x", 1840);
	set("coor/y", -6380);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
