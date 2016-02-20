// huixinshi.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "回心石");
	set("long", @LONG
从青柯坪沿石阶上山，山路到此而尽，前面山势险恶，石崖间仅有
窄窄的石阶犹如天梯耸立，两边铁链斜悬，令人不寒而栗，不敢前行。
北壁下大石当路，此石因此叫做回心石，再上去山道奇险，游客至此，
就该回了。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"qingke",
		"eastup"   : __DIR__"qianchi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x", -900);
	set("coor/y", 240);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
