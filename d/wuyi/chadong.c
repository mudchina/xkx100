// Room: /d/wuyi/chadong.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "茶洞");
	set("long", @LONG
茶洞又名玉华洞、升仙洞、碧玉洞，其实不是洞，是一片峥嵘深锁
的峡谷。三面岩壁环绕，地势幽深险要，飞瀑喷雪，石洞流水，幽绝尘
寰。清隐岩壁上“茶洞”二字，遒劲有力、韵味深长。这便是“臻山川
精英秀气所钟，品具岩骨花香之胜”的武夷岩茶的真正洞天仙府。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"westup"    : __DIR__"tianyoupath1",
		"southwest" : __DIR__"shaibuyan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -4980);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

