// npc: /d/city/npc/lulixian.c

#include <ansi.h>
inherit NPC;

int ask_riddle();

void create()
{
	set_name("陆丽仙", ({ "lu lixian", "lu", "lixian" }) );
	set("gender", "女性" );
	set("title", MAG"歌姬"NOR );
	set("nickname", YEL"金锭待系生"NOR);
	set("age", 18);
	set("long", 
"红羞翠怯，娇面含春，身穿时花绣袄，低束罗裙，貌如仙子，腰似小蛮，纤不盈握。\n");

	set("per", 28);
	set("int", 28);
	set("combat_exp", 5000);

	set("attitude", "peaceful");
	set("inquiry", ([
		"猜谜" : (: ask_riddle :),
		"谜语" : (: ask_riddle :),
	]) );
	set("times", 100);
	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
	}) );
	carry_object(CLOTH_DIR+"cloth/qi-dress")->wear();
	carry_object(CLOTH_DIR+"shoes")->wear();
}

void init()
{
	::init();
	add_action("do_answer", "answer");
	add_action("do_enjoy",  "enjoy");
}

int ask_riddle()
{
	object me = this_player();

	if( me->query("trill_marks/guessing") )
	{
		write("陆丽仙笑了笑，说：你先把上个谜猜出来再说。\n");
		return 1;
	}
	else
	{
		switch( (int)me->query("trill_marks/guess") ) {
		case 0:
			message_vision("陆丽仙巧笑着对$N说：咱们猜个谜语吧：\n", me);
			write("遥望山家正午炊 打《红楼梦》人名一\n");
			me->set("trill_marks/guessing", 1);
			break;
		case 1:
			message_vision("陆丽仙巧笑着对$N说：咱们猜个谜语吧：\n", me);
			write("飞渡蓬莱我不惧 打《红楼梦》诗句一\n");
			me->set("trill_marks/guessing", 2);
			break;
		case 2:
			message_vision("陆丽仙巧笑着对$N说：咱们猜个谜语吧：\n", me);
			write("潘金莲嫌武大   打《诗经》诗句一\n");
			me->set("trill_marks/guessing", 3);
			break;
		default :
			command("sigh");
			message_vision("陆丽仙对$N说道：谜都被你猜光了，等我制出新的再说吧！\n", me);
		return 1;
	}
	write("想好了回答 (answer) 我。记住，不可泄露谜语或谜底。\n");
	message("vision", "陆丽仙对着"+me->name()+"嘀咕了几句话。\n", environment(me), ({me}));
	return 1;
	}
}

int do_answer(string arg)
{
	object me;
	int soln,riddle;
	me = this_player();
	riddle = me->query("trill_marks/guessing");

	if (!riddle) {
		write("什么？你想干吗？\n");
		return 1;
	}

	if( !arg || arg=="" ) {
		write("想好谜底再回答。\n");
		return 1;
	}
	message("vision", me->name() + "把嘴凑到陆丽仙的耳边嘀嘀咕咕。\n", environment(me), ({me}) );

	switch (arg)
	{
	case "岫烟": soln=1; break;
	case "邢岫烟" : soln=1; break;
	case "任凭弱水三千" : soln=2; break;
	case "不如叔也" : soln=3; break;
	default :
		say("陆丽仙掩着嘴笑了起来，说道：不对，不对。\n"
		 + me->name() + "的脸唰的红了起来。\n");
	return 1;
	}

	if ( riddle == soln )
	{
		me->set("trill_marks/guess", riddle);
		message_vision("陆丽仙愉快的对$N微笑着。\n", me);
		me->set("score", me->query("score")+80);
		me->delete("trill_marks/guessing");
		write ("你的江湖阅历增加了！\n");
	}
	else
		write ("不对，不对！！瞎猜可不好！\n");
	return 1;
}

int do_enjoy()
{
	object me;
	string msg, me_msg;
	int jin, e_jin, m_jin, bonus;

	if( query("times") < 0)
		return notify_fail("陆丽仙疲惫地笑了笑：“今儿我累了，你改天再来吧。”\n");
	add("times", -1);
	me = this_player();
	me_msg="果然";
	if ( objectp( present( "zizhu xiao",me) ) )
		me_msg = "$N吹箫和之，声调清亮，音韵悠然，\n果然";
	msg = "陆丽仙笑了一声，徐将宝鸭添香，然后四弦入抱，半面遮羞，嘈嘈切切，错杂弹来。\n"+me_msg+"吹弹的清风徐来，枝鸟徐啼，悄然曲尽而尚袅余音。\n";
	message_vision(msg, me);
	jin = me->query( "jing" );
	e_jin = me->query( "eff_jing" );
	m_jin = me->query( "max_jing" );
	bonus = me->query_skill("literate",1) + me->query_per() - 60;
	if ( bonus < 0 ) bonus = 0;
	if ( bonus )
	{
		write("你听完一曲，觉得神完气足。\n");
		if ( jin < e_jin )
		{
			if ( ( jin + bonus ) > e_jin ) jin = e_jin;
			else jin += bonus;
		}
		me->set("jing", jin);
	}
	me->add("lu_sing", 1);
	return 1;
}

