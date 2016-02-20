// xizi.c
inherit NPC;
#include <ansi.h>
int ask_meili();

void create()
{
	set_name("戏子", ({ "xi zi", "xi","zi" }) );
	set("gender", "男性" );
	set("age", 10+random(40));
	set("int", 28);
	set("long","这是个很英俊的男子。\n");
	set("attitude", "peaceful");
	set_skill("literate", 100);
        set("combat_exp",random(10000));
	set("chat_chance", 3);
	set("chat_msg", ({
	"戏子突然说道: 魅力很重要，魅力高人人都喜欢。\n",
	"戏子得意地说: 我的魅力值是100。\n",
	"戏子突然说道: 这年月，要想当官不容易啊，魅力值太低可不行。\n",
	}));
        set("inquiry", ([
                "魅力" :  (: ask_meili :),
                "当官" :  "要想当官得进京见皇上去。\n",
	]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_meili()
{
	command("tell "+this_player()->query("id")+" 你现在的魅力值是 " +(string)(this_player()->query("meili")));
	say( "\n戏子说：如果你魅力值很高，有些人见了你会教你武功，送你宝贝。\n而且你还可以去宫里见皇上，如果他封你个官儿，你就可以带兵啦 。。。。。\n");
	say("戏子又说：不过当了官会有任务的，搞不好会杀头的。\n");
	return 1;
}

