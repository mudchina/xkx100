// npc: /d/city/npc/bookboss.c
// Last Modified by Winder on Jul. 15 2000

inherit NPC;
inherit F_DEALER;
int ask_me();
int ask_gong();

void create()
{
	set_name("辛友清", ({ "xin youqing","xin" }) );
	set("title","书局老板");
	set("gender", "男性" );
	set("book_count", 1);
	set("age", 38);
	set("long", "辛友清一看就是个读书人，他功名未就，但卖书贩画为生，也颇为自得。\n");
	set("attitude","friendly");
	set("inquiry",([
	       "书"    : "我这里什么书都有，你想买什么？\n",
	       "here"  : "这是我花了三百两银子买来的店铺。\n",  
	       "遗物"  : (: ask_me :),
	       "恩公"  : (: ask_gong :),
	]));
	set("vendor_goods",({
		"/clone/book/lbook1",
		"/clone/book/lbook2",
		"/clone/book/lbook6",
		"/clone/book/lbook7",
		"/clone/book/lbook8",
		"/clone/book/blade_book0",
		"/clone/book/blade_book1",
		"/clone/book/dodge_book1",
		"/clone/book/dodge_book2",
		"/clone/book/sword_book1",
		"/clone/book/cuff_book",
		"/clone/book/unarmed_book",
	}));
	set("chat_chance", 15);
	set("chat_msg",(
	{
	    "老板手里拿着一把鸡毛掸子，轻轻掸去墙上，书架上的尘土。\n",
	    "老板笑着问道：“买书？还是看看字画儿？”\n",
	    "老板轻声嘟喃着:识货者分文不取，不识者千金难求。\n",
	    "辛友清仰头叹道:何日才能见到恩公的后人啊。\n",
	}));
     
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
}
void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
	add_action("do_answer", "answer");
}
int ask_me()
{
	if ((int)this_player()->query_skill("literate",1)<125){ 
		say(
"辛友清白了白眼，对" + this_player()->name() + "说道：怎么看你也不象个读书人。\n");
            return 1;
        }else{
        say(
        "辛友清看了" + this_player()->name() + "一眼,神神秘秘的说道：\n"
        "请问您是谁的后人(answer)?\n");
        this_player()->set_temp("pending/answer",1);
        return 1;
      }
}
int ask_gong()
{
        tell_object(this_player(),
        "辛友清看了你一眼,神神秘秘的说道：\n"
        "恩公生前曾在此留有一部书籍，交待要悉心保管以传给后人。\n"
        "只是不知何时何人会来取书。\n"
        );
        return 1;
}
int do_answer(string arg)
{
	object me, ob, book;
	me = this_object();
	ob = this_player();
	if (!ob->query_temp("pending/answer")) return 0;
	ob->delete_temp("pending/answer");
	if (arg == "先祖司马迁" && query("book_count"))
	{
   add("book_count", -1);
	 book = new("/u/evil/lbook6");	
	 if ( book->violate_unique())
	 {
	  	destruct(book);
	    write("辛友清冲着" + ob->name() + "说道：可惜你晚来一步啊。\n");
	   	return 1;
	 }
		say(
"辛友清对" + ob->name() + "说道：今儿终于遇到恩人的后代拉。\n"
"我把先生的遗书交还给您拉。\n");
   book->move(ob);
	 message_vision("$N交给$n一本书。\n", me, ob);
	 command("rumor "+ob->query("name")+"拿到史记真篇啦。\n");
   return 1;
  }
   message_vision("$N笑道：原来先祖是"+arg+"啊，失敬失敬。\n",me);
   return 1;
}
