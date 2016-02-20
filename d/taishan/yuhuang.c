// Room: /d/taishan/yuhuang.c
// Last Modified by Winder on Aug. 25 2001
// Modified by Zeratul Jan 11 2001 江湖阅历低于10000不能见盟主

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "玉皇庙");
	set("long", @LONG
玉皇庙是处在泰山绝顶的庙观，古称太清宫、玉帝观，由山门、玉
皇殿、观日亭、望河亭、东西道房组成。山门额书“敕修玉皇顶”。正
殿内祀明代铜铸玉皇大帝像。神龛上匾额“柴望遗风”。远古帝王多在
此燔柴祭天，望祀山川诸神。观前为古登封台，历代皇帝封禅的仪式都
是在这里举行。台下有一无字碑，据说是汉武帝所立。
　　东南石坪宽敞，名平顶峰，上建乾坤亭，上刻“孔子小天下处”。
正中往上便是武林盟主所在之处—封禅台。
LONG );
	set("exits", ([
		"southdown" : __DIR__"nantian",
		"southeast" : __DIR__"riguan",
		"northwest" : __DIR__"zhangren",
		"east"      : __DIR__"guanriting",
		"west"      : __DIR__"wangheting",
		"up"        : __DIR__"fengchan",
	]));
	set("objects",([
		__DIR__"npc/jiang" : 1,
		__DIR__"npc/wei-shi2" : 3,
	]));
	set("coor/x", 360);
	set("coor/y", 780);
	set("coor/z", 210);
	setup();
}

int valid_leave(object me, string dir)
{
	object ob1, ob2, ob3;
	string mengzhu, shangshan, fae;
	
	if(!( ob1 = find_living("mengzhu")) )
		ob1 = load_object("/clone/npc/meng-zhu");
	mengzhu = ob1->query("winner");

	if(!( ob2 = find_living("shangshan")) )
		ob2 = load_object("/clone/npc/shang-shan");
	shangshan = ob2->query("winner");

	if(!( ob3 = find_living("fae")) )
		ob3 = load_object("/clone/npc/fa-e");
	fae = ob3->query("winner");

	if( dir == "up" )
	{ 
		if ( userp(me) && me->query("score") < 10000 )
			return notify_fail( "盟主是不会见你这种小人物的，还是回去吧。\n" );
		if( present("jiang baisheng", environment(me)) &&
			me->query("id") != mengzhu &&
			me->query("id") != shangshan &&
			me->query("id") != fae )
			return notify_fail("江百胜伸手拦住你说道：盟主很忙，现在不见外客，你下山去吧！\n");
		else if( me->query("id") == mengzhu )
		{
			message_vision(HIY "\n江百胜诚惶诚恐的向$N跪倒磕头，大声喊道：盟主万岁，万岁，万万岁！\n" NOR, me);
		}	
		else if( me->query("id") == shangshan )
		{
			message_vision(HIY "\n江百胜毕恭毕敬的向$N拜倒喊道：赏善使者您好！ 属下江百胜参见大人！\n" NOR, me);
		}	
		else if( me->query("id") == fae )
		{
			message_vision(HIY "\n江百胜毕恭毕敬的向$N拜倒喊道：罚恶使者您好！ 属下江百胜参见大人！\n" NOR, me);
		}	
	}

	return ::valid_leave(me, dir);
}
