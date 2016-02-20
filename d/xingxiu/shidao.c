// Room: /d/xingxiu/shidao.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;

void create()
{
	set("short", "石道");
	set("long", @LONG
这是一条两旁点缀花卉的小径。花儿发出的香味多多少少冲淡了周
围弥漫着沼泽的瘴气。来来往往都是星宿弟子，而且都是男的，哼着小
曲。西边有一山洞，洞里不时传来嬉笑声，其中也夹杂了哭叫求饶声。
LONG
	);
	set("outdoors","xingxiu");
	set("exits", ([ 
		"east"  : __DIR__"xiaojing",
		"enter" : __DIR__"xiaoyao",
	]));
	set("objects", ([ 
		CLASS_D("xingxiu")+"/caihua" : 1,
	]) );
	set("coor/x", -50200);
	set("coor/y", 20200);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if (dir =="enter" )
	{
		if (present("caihua zi", environment(me)))
		{
			if (!myfam || myfam["family_name"] != "星宿派") 
return notify_fail("采花子挡住了你：我的小妞可不是给你们邪派弟子准备的！\n");
			if  (me->query("gender")=="无性") 
return notify_fail("采花子挡住了你，一脸讥笑：您这小身板还想玩妞？别开玩笑了。\n");
			if (!(int)this_player()->query_temp("marks/花"))
return notify_fail("采花子挡住了你：喂，你总该意思意思吧？\n");
		}
		return 1;
	}
	return ::valid_leave(me, dir);
}

