// Room: /d/huangshan/shizi.c
// Last Modified by winder on Sep. 27 2001
inherit ROOM;
void create()
{
	set("short", "狮子峰");
	set("long", @LONG
远像是一头卧狮，头西尾东横卧于前。上面胜景无数，狮子林，麒
麟，宝塔等奇松，蒲团，凤凰等古柏都是罕见的美景，所以向有“没到
狮子峰，不见黄山踪”的盛誉。尤以北方的清凉台更为出名，向来是游
人必去之所。
LONG
	);
	set("exits", ([ 
		"northdown" : __DIR__"qingliang",
		"southdown" : __DIR__"paiyun",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huangshan");
	setup();
}
int valid_leave(object me, string dir)
{
	object ob;

	if( userp(me) && dir=="west" &&
		(ob=present("bai hong", this_object()) ||
		ob=present("bai huan", this_object())) &&
		me->query("bellicosity")>50)
		return notify_fail(ob->name()+"说道：请留步！\n");
	return 1;
}
void reset()
{
	object me,me2;

	:: reset();
	me2=present("bai huan", this_object());
	me=present("bai hong", this_object());
	if(me) me->dismiss_team();
	if(me2) me2->dismiss_team();
	if(me && me2) me->add_team_member(me2);
}
