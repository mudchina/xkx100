// Room: /d/fuzhou/nanmendou.c
// Date: may.12 1998 Java
inherit ROOM;

void create()
{
	set("short", "南门兜");
	set("long", @LONG
南门兜中央有一株巨大古榕，根繁叶茂，浓荫遮盖树亩，将整个街
口遮闭严实不漏日光。大榕树下有一小洞(dong)，深藏根下。
LONG );
	set("exits", ([ /* sizeof() == 1 */
	    "north"  : __DIR__"nandajie",
	    "south"  : __DIR__"nanmen",
	    "west"   : __DIR__"shiqiao",
	    "east"   : __DIR__"xiaochang",
	]));
	set("objects", ([
		__DIR__"npc/wu" : 1,
	]));
	set("item_desc", ([
	    "dong"   : "一个深邃幽暗的洞穴。\n",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6320);
	set("coor/z", 0);
	setup();
}
void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
        object me;
        mapping fam;

        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="dong" )
        {
           if( (fam = me->query("family")) && fam["family_name"] == "丐帮")
           {
               message("vision",
                        me->name() + "运起丐帮缩骨功，一弯腰往洞里钻了进去。\n",
                        environment(me), ({me}) );
               me->move("/d/gaibang/underfz");
               message("vision",
                        me->name() + "从洞里走了进来。\n",
                        environment(me), ({me}) );
                        return 1;
           }
           else  return notify_fail("这么小的洞，你钻得进去吗？\n");
       }
}
