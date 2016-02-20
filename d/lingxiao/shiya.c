// Room: /d/lingxiao/shiya.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","石崖");
	set("long",@LONG
转过山梁，几块青石相互交搭，组成了一个避风的石崖。外面朔风
飞扬，里面却炉火熊熊，松木流爆，传来丝丝烤肉的香味，凌霄弟子巡
山至此，常在这里避风休憩。旁边有个小店，疲累饥渴时，可在里面稍
事休息。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"east"     : __DIR__"bar", 
		"westdown" : __DIR__"sroad3",
		"northup"  : __DIR__"sroad4",
	]));
	set("objects",([ /* sizeof() == 1 */
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", -31000);
	set("coor/y", -8980);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

