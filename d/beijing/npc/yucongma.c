// yucongma.c
inherit NPC;
inherit F_UNIQUE;
#include <ansi.h>
void create()
{
	set_name(HIC "玉骢马" NOR, ({ "yu cong ma","yu","ma"}));
	set("race", "走畜");
	set("gender", "雄性");
	set("age", 2+random(3));
	set("long", "这是一匹玉骢宝马，日行千里，夜行八百。\n");
//		"玩家可以骑上它去任何地方(ride/down)。\n"
	set("int", 30);
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 100);
	set("max_jing", 100);
	set("shen_type", 0);
	set("combat_exp",50000);
	set("attitude", "peaceful");

	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);

	setup();
}

void init()
{
	add_action("do_ride", "ride");
//	add_action("do_go", "go");
	add_action("do_down", "down");
	remove_call_out("destme");
	call_out("destme", 90);
}
void destme()
{
	message_vision("$N长嘶一声，掉头回北京康亲王府去了。\n",this_object());
	destruct(this_object());
}		    

int do_ride ( )
{
	string dir,dir2;
	object ob = this_player () ;
	if(ob->query("meili")<20)
	{
		message_vision("$N一跃身跨上了玉骢马。只见玉骢马仰天长啸，突然猛然一颠......\n"HIR"把$N狠狠摔在了地上，结果$N受了点轻伤。\n" NOR,ob);
		ob -> receive_damage ("qi",50) ;
		ob -> receive_wound  ("qi",50) ;
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
		return 1;
	}
	if( objectp(query("rider"))) 
	{
		return notify_fail("现在马上已经有人了！\n" ) ;
	}
	else
	{    
		ob->set_temp("onhorse",1);
		this_object()->set("rider",this_player());
		message_vision("$N一跃身跨上了玉骢马。\n" , ob );
		this_object()->set_leader(this_player());
		command("follow "+ob->query("id"));
		write("请输入要去的地名, 示例(go baituo):\n"+
		"	 beijing:  北京城\n"+
		"	 yangzhou: 扬州城\n"+
		"	 shaolin:  少林寺\n"+
		"	 taohua:   桃花岛\n"+
		"	 baituo:   白陀山\n"+
		"	 xingxiu:  星宿海\n"+
		"	 xueshan:  雪山寺\n"+
		"	 huashan:  华  山\n");
		return 1; 
	}
}

int do_down()
{
	object ob = this_player () ;

	if(!objectp(query("rider"))) return notify_fail("马上没人。\n");
	if(ob->query_temp("onhorse"))
	{
		message_vision("\n$N身行一转，跃下马来，姿态十分优美。\n", ob);
		delete("rider");
		command("follow none");
		ob->delete_temp("onhorse");
	}
	else 
		switch(random(3))
		{
			case 0: 
				message_vision("\n$N一把把马上的人拉下来，想自己跳上去。\n" , ob );
				command("follow none");
				query("rider")->delete_temp("onhorse");
				delete("rider");
				ob->set_temp("onhorse");
				break;
			case 1: 
			case 2:
				message_vision("\n$N想把马上的人拉下马来，但没有成功。\n" , ob );
	}	  
	return 1;
}

int do_go ( string arg )
{
    object ob ;
    ob = this_player () ;
    if( !arg || arg=="" )  return notify_fail("你要去哪儿？\n");
    if(!ob->query_temp("onhorse")) return notify_fail("你还没上马。\n");
    message_vision("\n只见$N骑两腿一夹，玉骢马向前急驰而去。\n" , ob );
    switch (arg)
    {
	 case "baituo": 
	       remove_call_out("baituo");
	       call_out("baituo", 10, ob);
	       return 1 ;
	 case "xueshan": 
	       remove_call_out("xueshan");
	       call_out("xueshan", 10, ob);
	       return 1 ;
	 case "taohua": 
	       remove_call_out("taohua");
	       call_out("taohua", 10, ob);
	       return 1 ;
	 case "huashan": 
	       remove_call_out("huashan");
	       call_out("huashan", 10, ob);
	       return 1 ;
	 case "beijing": 
	       remove_call_out("beijing");
	       call_out("beijing", 10, ob);
	       return 1 ;
	 case "xingxiu": 
	       remove_call_out("xingxiu");
	       call_out("xingxiu", 10, ob);
	       return 1 ;
	 case "shaolin":
	       remove_call_out("shaolin");
	       call_out("shaolin", 10, ob);
	       return 1 ;
	case "yangzhou": 
	       remove_call_out("yangzhou");
	       call_out("yangzhou", 10, ob);
	       return 1 ;
    }
    return notify_fail("没有这个地方\n");
}

void baituo(object ob)
{
    ob->move("/d/baituo/damen");
    this_object()->move("/d/baituo/damen");
    message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
    message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
void xueshan(object ob)
{
    ob->move("/d/xueshan/shenghu") ;
    this_object()->move("/d/xueshan/shenghu");
    message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
    message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
void taohua(object ob)
{
    ob->move("/d/guiyun/qianyuan") ;
    this_object()->move("/d/guiyun/qianyuan");
    message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
    message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
void huashan(object ob)
{
    ob->move("/d/huashan/path1") ;
    this_object()->move("/d/huashan/path1") ;
    message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
    message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
void beijing(object ob)
{
    ob->move("/d/beijing/tian_anm") ;
    this_object()->move("/d/beijing/tian_anm") ;
    message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
    message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
void xingxiu(object ob)
{
    ob->move("/d/xingxiu/xxroad2") ;
    this_object()->move("/d/xingxiu/xxroad2") ;
    message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
    message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
void shaolin(object ob)
{
    ob->move("/d/shaolin/shanmen") ;
    this_object()->move("/d/shaolin/shanmen") ;
    message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
    message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
void yangzhou(object ob)
{
    ob->move("/d/beijing/guangchang") ;
    this_object()->move("/d/city/guangchang") ;
    message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
    message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
