// laojun.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "老君沟");
	set("long", @LONG
爬过两个要命的悬崖，可在这里稍作歇息。老君沟是一条半里多长
的山沟，相传为太上老君到此，见无路可通，因而套上大青牛用铁犁犁
出了这条沟作为登山通道。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"pingxinshi",
		"southup"  : __DIR__"husun",
	]));
	set("objects", ([
		 __DIR__"npc/lao-denuo": 1,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -870);
	set("coor/y", 230);
	set("coor/z", 70);
	setup();
}
 
int valid_leave(object me, string dir)
{
	if ((me->query("family/family_name") == "华山派剑宗") &&
		dir == "southup" &&
		objectp(present("lao denuo", environment(me))))
		return notify_fail("劳德诺劝道：家师有交代，剑宗廿五年前就离开华山了，自认不是华山弟子了。\n我虽是老好人，这位" + RANK_D->query_respect(me) + "还是请回吧。\n");
	return ::valid_leave(me, dir);
}
 
