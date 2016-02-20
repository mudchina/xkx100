// Last Modified by Winder on May. 15 2001
// axiang.c
inherit NPC;

int ask_letter();

void create()
{
	set_name("阿祥", ({ "nongfu" , "a xiang", "a", "xiang" }) );
	set("nickname", "农夫");
	set("gender", "男性" );
	set("age", 44);
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("rank_info/respect", "农民伯伯");
	set("inquiry", ([
		"name"   : "俺叫阿祥，不过俺不是这里土生土长的人。",
		"rumors" : "真怀念年轻时和阿根一起盗墓的时光呀。",
		"here"   : "这里是曹娥江，你看到那块碑了吗？背后的文字是东汉蔡邕读完碑文后写的，不知道是什么意思，好难理解呀！",
		"碑"     : "就在那边呀，你不会没看见吧？",
		"字"     : "蔡邕写的那八个字吗？自己看去！",
		"文字"   : "蔡邕写的那八个字吗？自己看去！",
		"阿根"   : "小时候的好伙伴了，我现在来到这里，他却还留在大理。",
		"铁铲"   : "嘿嘿，要铁铲做什么？难不成你也想盗墓？",
		"盗墓"   : "那是以前干的勾当啦。干这种活需要好工具呀，普通的铁铲什么的可不顺手！",
		"工具"   : "我这里没有啦，阿根那里可能还有。不过听说他在大理当了大官，不会再干这个了。如果我写封信去，他也许还会卖我这个老脸。",
		"信"     : (: ask_letter :),
	]) );
	setup();
}

void init()
{
	add_action("do_answer", ({"answer", "huida", "da"}));
	::init();
}

int ask_letter()
{
	this_player()->set_temp("axiang_letter", 1);
	say( "农夫说道：“要我写信也成，不过你得先告诉(answer)我碑后面那八个字的意思。”\n");
	return 1;
}

int do_answer(string arg)
{
	object ob, me = this_player();
	int flag;

	if (!(flag = me->query_temp("axiang_letter"))) return 0;
	if (!arg) return notify_fail("你要回答什么？\n");
	if (arg == "绝妙好辞")
	{
		write( "你说道：“这不过是隐语罢了。‘黄绢’是颜色之丝，乃‘绝’字；‘幼妇’者，少女也，乃‘妙’字；‘外孙’，女之子，乃‘好’字；‘齑臼’，受五辛之器，是为‘辞’字。所以意思是‘绝妙好辞’。”\n");
		tell_room(environment(), me->name() + "对着农夫侃侃而谈。\n", ({me}));
		if (flag == 2)
		{
			command("kick " + me->query("id"));
			message_vision("$N骂道：“你不是说过一遍了吗？怎么又来罗嗦！”\n", this_object());
		}
		else
		{
			message_vision("$N一拍大腿：“我怎么没有想到呀！”\n", this_object());
			write("阿祥说：“好吧，我就写封信给阿根。”\n");
			me->set_temp("axiang_letter", 2);
			ob = new(__DIR__"obj/axiang_xin");
			ob->move(me);
		}
	}
	else
	{
		message_vision("$N道：“容易！不就是" + arg + "的意思嘛。”\n", me);
		command("laugh " + me->query("id"));
		message_vision("农夫对$N说道：“我本以为自己是天底下最没文化的，现在看来只能排第二了。”\n", me);
	}
	return 1;
}

