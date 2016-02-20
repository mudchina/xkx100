// Room: /d/nanshaolin/songshu4
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "松树林");
	set("long", @LONG
这是一片松树林。高高的大松树簇在一块，密实的枝叶象一蓬蓬巨
伞般伸向天空，把阳光遮得丝毫也无。一条洁净的青石小径蜿蜒林中。
东面的院落就是戒律院。院外站着两名僧人严密的守护着。
LONG
	);
	set("outdoor","nanshaolin");
	set("exits", ([
		"west" : __DIR__ "songshu3",
		"east" : __DIR__ "jieluyuan",
	]));
	set("objects",([
		__DIR__"npc/zjseng" : 1,
		__DIR__"npc/slseng" : 1
		
	]));
	set("coor/x", 1830);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping fam;
	if (dir == "east")
	{
		if( mapp(fam = me->query("family")) &&
			fam["family_name"] == "南少林派" &&
			fam["generation"] <= 20 )
			return ::valid_leave(me, dir);
		if( me->query("guilty") == 0 || !userp(me) &&
			me->query("id") != "seng bing" )
		{
			return notify_fail("只听院内传来一个浑厚的声音说道：你未经许可，不能进入戒律院。\n");
		}
	}
	return ::valid_leave(me, dir);
}

