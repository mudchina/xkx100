// Npc: /d/guiyun/npc/zhanggui.c
// Last Modified by winder on Jul. 9 2001

inherit NPC;

void create()
{
	set_name("掌柜", ({ "zhang gui", "zhanggui", "zhang" }) );
	set("gender", "男性" );
	set("age", 52);
	set("long",
		"这位老掌柜正在忙着敲打算盘。\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	set("inquiry", ([
		"name" : "不瞒客官说，小老儿的小名实在难听，叫做赵阿狗。",
		"rumors" : "归云庄的弟子们总来这里，有时候谈到桃花岛，都流露出向往的神情。",
		"here" : "这里是太湖边，往北走就可以看到归云庄了。",
		"桃花岛": "听说是东海上的小岛，往杭州的东南走，到海边看能不能雇船吧？",
		"生意" : "因为归云庄的弟子们总来照顾小店的生意，所以还算不错。",
		"归云庄" : "向北走就能看到。那里的庄主姓陆，平时难得见到。",
	]) );
	setup();
}

void init()
{	
}

int accept_object(object who, object ob)
{
	int pay, value;

	if (ob->query("money_id")) {
		if (!(pay = who->query_temp("total_pay"))) {
			tell_object(who, "掌柜忙不迭地笑道：“客官您又不欠小店的钱，就别拿老头儿寻开心了。”\n");
			return 0;
		}
		if (!who->query_temp("to_pay")) {
			tell_object(who, "掌柜说道：“客官您先结帐(pay)再付款。”\n");
			return 0;
		}
		value = ob->value();
		if (value >= pay) {
			who->delete_temp("to_pay");
			who->delete_temp("total_pay");
			if (value == pay) message_vision("掌柜满脸堆着笑，冲$N哈腰道：“谢客官您啦，走好。”\n", who);
			else message_vision("掌柜满脸堆着笑，冲$N哈腰道：“谢客官您的小费，老儿不客气就收下了，您走好。”\n", who);
			return 1;
		}
		else {
			pay -= value;	
			message_vision("掌柜对着$N说道：“不够！还差" + chinese_number(pay) + "文。”\n", who);
			who->set_temp("total_pay", pay);
			return 1;
		}
	}
	return 0;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N沮丧地发现掌柜站在高高的柜台后面，够不到。\n", ob);
}

void unconcious()
{
	say( "掌柜大喊一声：“我不行了，快来接班！”\n");
	say( "结果从柜台后面又钻出一个掌柜来，说：“没问题，交给我吧。”\n");
	say( "前一个掌柜呲牙咧嘴地离开了。\n");
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

void die()
{
	unconcious();
}

