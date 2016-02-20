// Feb. 6, 1999 by Winder
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("阿凤", ({ "a feng","a","feng"}) );
	set("gender", "女性" );
	set("age", 16);
	set("long", "这是一个活泼可爱的女仆人。\n");
	set("shen_type", 1);
	set("combat_exp", 500);
	set("str", 16);
	set("dex", 17);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	set("chat_chance",1);
	set("chat_msg",({
	    "阿凤一边微笑着，一边不知道在想什么心事。\n",
	    "阿凤自言自语地说：阿土那个死人，连人家的心意都不知道。\n",
	    "阿凤叹了口气道：女大思春啊！\n",
            "阿凤突然说道：我家小姐好惨啊，被关在这个岛上不许出去。\n"
	   }) );
       set("inquiry",([
	   "阿土" : "他是我的心上人啊，但我不知道他的心意如何，这种事情叫我一个女孩子家怎么说得出口嘛。\n"
	   ]) );
       setup();
       carry_object("/clone/misc/cloth")->wear();
}
int accept_object(object me, object ob)
{
        if( !me || environment(me) != environment() ) return 0;
        if ( !objectp(ob) ) return 0; 
        if ( !present(ob, me) ) return notify_fail("你没有这件东西。");
        if ( (string)ob->query("id") == "qing shu") 
        {
         write(HIC "阿凤一把抢过你送来的情书，高兴地跳了起来，说道: \n" NOR);
         write(HIC "既然你对我这么好，我就告诉你一个秘密。这里是可以\n" NOR);         
         write(HIC "出去的。你只需在《兰亭集序》下磕九个头就可以了！\n" NOR);
        }               
        return 1;
}
