// xiaodao1.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一条长长的林间小道，从东边一直通到西边，一眼望去，看不
到路的尽头。两旁百花争艳。令人留连忘返。
LONG
	);
	set("exits", ([
		"east" : __DIR__"qingcaop",
		"west" : __DIR__"xiaodao2",
	]));
 	set("objects", ([
		CLASS_D("xiaoyao")+"/goudu": 1,
	]));
	set("outdoors", "xiaoyao");
// 	set("no_clean_up", 0);
	set("coor/x", 70);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="west" && (!me->query("family") || me->query("family")["family_name"]!="逍遥派"))
                return notify_fail("路中间竖着一个“小牌”，上面写到：非逍遥派弟子，请勿进入。\n");
        return ::valid_leave(me,dir);
}