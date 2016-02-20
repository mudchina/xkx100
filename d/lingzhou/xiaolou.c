// Room: /d/lingzhou/xiaolou.c

inherit ROOM;

void create()
{
	set("short", "小楼");
	set("long", @LONG
这是一幢三层楼的木制建筑。端的是金碧辉煌，气象万千。赫连铁
树住在这里。底层是一排落地长窗和朱红色的圆柱。二楼有个小阳台，
三楼楼顶的琉璃瓦在阳光下闪闪发光，和皇城大殿的金顶同为全城都可
看到的建筑。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"jjdayuan",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/yahuan" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -17950);
	set("coor/y", 32040);
	set("coor/z", 0);

	setup();
	replace_program(ROOM);
}
