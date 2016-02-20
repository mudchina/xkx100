// Room: /qingcheng/zhongmen.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "穿廊门");
	set("long", @LONG
这里是松风观通往后院的中门，门厚三寸，红松铜箍，数十年犹有
松香飘荡，和观中香火掺和出一股出世的滋味。外派人士到此就该回头
了。
LONG );
	set("exits", ([
		"south" : __DIR__"qiandian",
		"north" : __DIR__"zoulang1",
	]));
	set("objects", ([
		__DIR__"npc/yu" : 1,
	]));
	set("coor/x", -8080);
	set("coor/y", -860);
	set("coor/z", 90);
	setup();
}

int valid_leave(object me, string dir)
{
/*	mapping myfam;
	myfam = (mapping)me->query("family");
	if ((!myfam || (myfam["family_name"] != "青城派")) && (dir == "north"))
		return notify_fail("非青城弟子，到此止步吧。\n");
	else return 1;
*/
if (dir != "south" )
	{
		if(me->query("family/family_name") !="青城派")
		{			
		       if(present("yu renhao", environment(me)) && living(present("yu renhao", environment(me))))
			{
				return notify_fail(
"于人豪喝道：后面是本派重地，这位" + RANK_D->query_respect(me) + "请止步。\n");
			}
			else
				return ::valid_leave(me, dir);			
		}
		else
			return ::valid_leave(me, dir);
	}
	else
		return ::valid_leave(me, dir);	
}
