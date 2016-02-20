// husun.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "猢狲愁");
	set("long", @LONG
前面又是一处十分陡峭的山岭，上面有四只铁猿，盘踞台畔，据说
以前从华山水帘洞出来的猿猴，每到这里就要返回去，连它们也感到难
于超越，此岭因而得名。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"laojun",
		"southup"   : __DIR__"shangtianti",
	]));
	set("objects", ([ /* sizeof() == 2 */
		"/d/wudang/npc/monkey": 1,
		"/d/wudang/npc/little_monkey": 2,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -870);
	set("coor/y", 220);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}
 
