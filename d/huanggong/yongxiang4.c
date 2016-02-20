// Room: /d/huanggong/yongxiang4.c

inherit ROOM;

void create()
{
	set("short", "永巷");
	set("long", @LONG
这里是三大殿周围的通道。宫禁森严，天威莫测，来来往往的宫女
太监虽然很多，可是谁也不敢带出一点声来。
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"yongxiang3",
		"north" : __DIR__"jingyunmen",
		"west"  : __DIR__"baohedian",
	]));
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}