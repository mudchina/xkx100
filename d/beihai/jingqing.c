// /d/beihai/jingqing.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "静清斋");
	set("long", @LONG
北岸之镜清斋（后改名为静心斋）为一精美之园中园，是清太子来
游时之居所，入门为荷池，池北为堂，堂后临山池，左右皆峰峦岩洞，
往昔有飞瀑流水往还萦回。池中有敞阁三间，名沁泉廊，廊后有山石回
抱，为乾隆时迭石之精品。遍布之太湖石山景，玲珑剔透，与隐现在翠
竹花木中的亭台轩桥互相辉映，景色幽雅。
LONG
	);

	set("exits", ([
		"east"      : __DIR__"houmen",
		"southwest" : __DIR__"xitian",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -170);
	set("coor/y", 4100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
