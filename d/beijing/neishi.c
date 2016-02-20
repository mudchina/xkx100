//neishi.c

inherit ROOM;

void create()
{
	set("short", "内室");
	set("long",
	     "\n这里是一个空荡荡的房间，除了地板(floor)，什么也没有。\n"
	);
	set("exits", ([
		"east" : __DIR__"huichunt",
	]));
	set("item_desc", ([
		"floor" : "\n地板全是木制的，上面积了些灰尘，不过有一块木板很干净。\n" ,
	]));
	set("no_clean_up", 0);
	set("coor/x", -211);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_move", "move");
        add_action("do_move", "open");
        add_action("do_knock", "knock");
}


int do_move(string arg)
{
        object me;
        me = this_player();
        if (!arg||arg!="floor") return notify_fail("你要移开什么？\n");
	message_vision(
		"\n$N掀开棺材板，只听“唰”的一声, 地道里突然白光一闪，\n"+
		"一柄长剑倏的伸出,“噗”的一声刺入了$N的小腹,又“噗”的一声拔了出来。\n"+
                "一个道人从洞里探出头来，满脸不屑地看了$N一眼，又伸手把地板关上了。\n", this_player());
        if((int)this_player()->query("qi")<250) this_player()->die();
        else this_player()->unconcious();
	return 1;
}

int do_knock(string arg)
{
        object me,hole;
	string dir;
        me = this_player();
        if (!arg||arg=="") return 0;
	if( arg=="floor" ) {
		message_vision("\n$N试著敲了敲地板，声响清脆，下面似乎是空心的。\n", this_player());
	}
	if( sscanf(arg, "floor %s", dir)==1 ) 
	{
		if( dir=="3" || dir=="three") {
		if(!objectp(present("hole", environment(me))))
		{
		message_vision("\n$N在木板上咚咚咚敲了三下，只听吱呀一声，\n"+"里边伸出一双手把地板掀开了。\n", this_player());
                hole = new(__DIR__"obj/hole");
                hole->move(__DIR__"neishi");
		}
	        }   
		else return notify_fail("\n你胡乱敲了木板几下，结果什么也没发生。\n");
	}		
return 1;
}

int do_enter(string arg)
{
 if( !arg || arg!="floor" ) return 0;
 return notify_fail(" 想穿地板啊？你不会奇门遁甲。\n");
 return 1;
}	
