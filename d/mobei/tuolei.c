// Room: /d/mobei/tuolei.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "拖雷营帐");
	set("long", @LONG
拖雷是铁木真的四儿子，也是大汗最钟爱的儿子。他聪明梯透，行军打
战的才华远在诸兄之上。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/tuolei" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"road",
	]));
	set("coor/x", -220);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
