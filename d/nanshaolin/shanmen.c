// Room: /d/nanshaolin/shanmen.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
void init();
int do_open();
int valid_leave();
string look_gate();

void create()
{
	set("short", "少林山门");
	set("long", @LONG
转过山坳，举目望去，山谷里一大片房屋都是碧瓦黄墙，却是一座
大丛林。到庙前抬头一望，见山门(gate)正中金字写着“少林古刹”四
个大字。原来这里就是南少林寺。福建少林寺虽是嵩山下院，但南方莆
田少林下院的武功与嵩山少林一脉相传，寺中僧人武功之强，不下嵩山
本寺。
LONG );
	set("outdoors", "nanshaolin");
	set("item_desc",([
		"gate" : (: look_gate :),
	]));
	set("objects", ([
		CLASS_D("nanshaolin")+"/yuantong" : 1,
		CLASS_D("nanshaolin")+"/fangqiong" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"guangchang",
	]));
	set("coor/x", 1820);
	set("coor/y", -6300);
	set("coor/z", 10);
	setup();
//	"/clone/board/nanshaolin_b"->foo();
}

void init()
{
	add_action("do_knock", "knock");
}

int close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"gchang-1")) )
		room = load_object(__DIR__"gchang-1");
	if(objectp(room))
	{
		delete("exits/north");
		message("vision","乒地一声，里面有人把大门关上了。\n",this_object());
		room->delete("exits/south");
		if (objectp(present("yuan tong", room)))
			message("vision","元痛上前把大门关了起来。\n",room);
		else message("vision","壮年僧人上前把大门关了起来。\n",room);
	}
	else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_knock(string arg)
{
	object room;

	if (query("exits/north")) return notify_fail("大门已经是开着了。\n");

	if (!arg || (arg != "gate" && arg != "north"))
		return notify_fail("你要敲什么？\n");

	if(!( room = find_object(__DIR__"gchang-1")) )
		room = load_object(__DIR__"gchang-1");
	if(objectp(room))
	{
		set("exits/north", __DIR__"gchang-1");
		message_vision("$N轻轻地敲了敲门，只听吱地一声，一位壮年僧人应声打开大门，\n他用锐利的目光上上下下打量着$N。\n", this_player());
		room->set("exits/south", __FILE__);
		message("vision","外面传来一阵敲门声，壮年僧人应声上前把大门开。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( dir != "north" )
	{
		return ::valid_leave(me, dir);
	}
	if ( (me->query("family/family_name") == "少林派") ||
		(me->query("family/family_name") == "南少林派"))
	{
		if (((int)me->query("guilty") == 0) &&
			((int)me->query("K_record") == ((int)me->query("PKS") + (int)me->query("MKS"))))
		{
			message_vision("壮年僧人侧身让开，说道：师兄辛苦了，请进。\n", me);
			return 1;
		}
		else
		{
			if((int)me->query("guilty") == 0)
			{
				if((int)me->query("shen_record") >
					(int)me->query("shen"))
					me->set("guilty", 1);
				else me->set("guilty", 2);
				me->set("K_record", me->query("PKS") + me->query("MKS"));
				me->set("shen_record", me->query("shen"));
			}
			write("壮年僧人沉下脸来，说道：戒律院主持大癫大师请师兄\n火速去戒律院陈述此行过犯。\n");
			return 1;
		}
	}
	else if( present("yingxiong ling", me) )
		{
			message_vision("壮年僧人合十为礼，侧身让开，说道：原来是贵客驾到，请进请进！\n", me);
			return 1;
		}
    
	if (me->query("shen") >= 0)
	{
		if (me->query("gender") == "女性")
		{
			return notify_fail("壮年僧人说道：这位女施主还是请回罢，本寺从不接待女客。\n");
		}
		else
		{
			return notify_fail("壮年僧人说道：这位施主请回罢，本寺不接待俗人。\n");
		}
	}

	return notify_fail("壮年僧人立时从身畔挚出一把雪亮的戒刀来，把明晃晃的\n刀尖对准你的胸口，横眉怒目地说道：你等邪魔外道，还不给我滚开！\n以后再敢走近少林一步，我立时就斩断你们的狗腿！\n");
}

string look_gate()
{
	return "一道三丈来高的朱红杉木包铜大门。\n";
}
