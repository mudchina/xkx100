// kurong.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_me();
string ask_six();
string ask_join();
int accept_fight(object ob);
int checking(object me, object ob);
string* names = ({
	"ben yin",
	"ben can",
	"ben chen",
	"ben guan",
	"ben xiang",
	"ku rong",
});
void create()
{
	set_name("枯荣大师", ({ "ku rong","ku"}) );
	set("gender", "男性" );
	set("title", "天龙寺第十六代僧人");
	set("class", "bonze");
	set("long", 
"他的面容奇特之极，左边的一半脸色红润，皮光肉滑，有如婴儿，
右边的一半却如枯骨，除了一张焦黄的面皮之外全无肌肉，骨头突
了出来，宛然便是半个骷髅骨头。这是他修习枯荣禅功所致。\n");
	set("age", 100);
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 50);
	set("combat_exp", 1000000);
	set("score", 1000000);
	set("book_count", 1);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("finger", 200);
	set_skill("sword", 200);
	set_skill("tiannan-step", 200);
	set_skill("kurong-changong", 200);
	set_skill("duanjia-sword", 200);
	set_skill("six-finger", 200);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "six-finger");
	map_skill("finger", "six-finger");
	map_skill("sword", "duanjia-sword");
	prepare_skill("finger","six-finger");

	set("inquiry" ,([
	"剃度"	: (: ask_join :),
	"出家"	: (: ask_join :),
	"六脉剑阵" : (: ask_six :),
	"六脉神剑阵" : (: ask_six :),
	"六脉神剑" : (: ask_me :),
	"六脉神剑谱" : (: ask_me :),
	"六脉神剑剑谱" : (: ask_me :),
	]));
	create_family("大理段家",16,"高僧");

	setup();
	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}

void init()
{
	add_action("do_kneel", "kneel");
}

int ask_me()
{
        if ((int)this_player()->query_temp("marks/find_temp")&&this_player()->query_temp("marks/ask_temp3")) 
		{
        	say(
"枯荣看了" + this_player()->name() + "一眼，说道：\n"
"这位施主果然聪明，施主若能胜过老衲就可得到六脉神剑谱。\n");
       		return 1;
        }
}

int accept_fight(object ob)
{
        object me;

        me = this_object();
      
        if( ob->query_temp("marks/find_temp")&&ob->query_temp("marks/ask_temp3") ) {
           say(ob->name() + "对枯荣说：好吧，那" 
             "我就同你切搓几招吧，点到为止。\n");
	  remove_call_out("checking");
          call_out("checking", 1, me, ob);
          return 1;
        }
        else
    	  return 0;
}

int checking(object me, object ob)
{

        object obj;
        int my_max_qi, his_max_qi;
        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

        if (me->is_fighting()) 
        {
                call_out("checking",2, me, ob);
                return 1;
        }

        if ( !present(ob, environment()) ) return 1; 

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
                say(
                  "枯荣说：施主身手果然不凡，老衲佩服。\n"
                  "六脉神剑谱是没有的了，这本一阳指诀你先拿去吧。\n"
                );
                obj= new("/clone/book/sun_book"); 
                obj->move(ob);
message("channel:rumor", MAG"【谣言】某人："+this_player()->query("name")+"获得了一阳指诀啦。\n"NOR, users());
                message_vision("$N交给$n一本书。\n", me, ob);
                return 1;
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                say(
                   "枯荣双手合十道：尘缘一切自心起，施主请回吧。\n"
                );
                message_vision("$N对枯荣大师恭恭敬敬地磕了一个头，离开牟尼堂。\n", ob);
                ob->move("/d/tianlongsi/banruotai");
                return 1;
        }
        return 1;
}

string ask_six()
{
	mapping skl; 
        object fighter, me, room, monk;
	string *sname;
	int i,j;

	fighter = this_player();
	me = this_object();

	skl = fighter->query_skills();
	if (sizeof(skl) <= 1)
		return RANK_D->query_respect(fighter) + 
		"功力不够，不够资格闯六脉剑阵。";
	sname  = keys(skl);
	for(i=0; i<sizeof(skl); i++) {
		if ((skl[sname[i]] < 80) || (sizeof(skl) == 0))
		return RANK_D->query_respect(fighter) + 
		"，你这点本事也想闯六脉剑阵。";
	}

	if ( me->query("assigned_fighter") )
		return RANK_D->query_respect(fighter) + 
		"，今日已有人挑战六脉剑阵，你过一段时间再来吧。";

	say("\n枯荣大师道：好吧，你一会来般若台找我吧。\n");

	me->set("assigned_fighter", fighter->query("id")); 		
	
	message_vision("\n枯荣大师往北离开。\n\n", fighter);

	if(!( room = find_object("/d/tianlongsi/baodian")) )
		room = load_object("/d/tianlongsi/baodian");
	me->move(room);

	if( !objectp(monk = present("ben yin", room) ))
	{
		move("/d/tianlongsi/munitang");
		message_vision("\n枯荣大师走了过来。\n\n", fighter);
			return "真是对不起，本因方丈不在，无法举行六脉剑阵。\n";	
	}

	message("vision", "\n枯荣大师走了过来，跟" + monk->query("name") + "俯耳轻声说了几句。\n", room, monk);
	message("vision", monk->query("name") + "点了点头，快步走了出去。\n", room, monk);
	monk->move("/d/tianlongsi/munitang");
	me->move("/d/tianlongsi/munitang");
	message("vision", monk->query("name") + "快步走了过来。\n", room, monk);

	for(j=2; j<6; j++) 
	{
		if(!( room = find_object("/d/tianlongsi/munitang")) )
                room = load_object("/d/tianlongsi/munitang");
  		me->move(room);

		if( !objectp(monk = present(names[j-1], room) ))
		{
	        	me->move("/d/tianlongsi/munitang");
        	        message_vision("\n枯荣大师走了过来。\n\n", fighter);
			return "真是对不起，"+monk->query("name")+"不在，无法举行六脉剑阵。\n";	
		}
	}

	me->move("/d/tianlongsi/banruotai");
        call_out("waiting", 1, me);
	return "好！大家都出来了。\n";
}

int waiting(object me)
{
	object fighter;
	int wait_time;

	if( wait_time == 300 )
	{
		say( "枯荣大师说道：看来他不会来了，我们回去罢！\n\n");
		call_out("do_back", 0, me);		
	}

	if( !objectp( fighter = present( me->query("assigned_fighter"), environment(me) ) ) )
	{
		wait_time++;
		call_out("waiting", 1, me);
	}
	call_out("preparing", 1, me, fighter);

	return 1;
}

int preparing(object me, object fighter)
{
	object monk, room, ob;

	if(!( room = find_object("/d/tianlongsi/banruotai")) )
	room = load_object("/d/tianlongsi/banruotai");

	message("vision", HIY "\n枯荣大师大声宣布：六脉剑阵合围！\n" NOR, room);
	message("vision", "\n只听四周声声佛号，天龙寺高僧们个个神情肃杀，\n"
		"慢慢地从牟尼堂中鱼贯步出，围住了通路。\n\n", room);
	room->delete("exits");

	say( "枯荣又道：准备，六脉剑阵即刻发动！\n\n");

	fighter->delete_temp("beat_count");
	fighter->set_temp("fighting", 1);

	call_out("fighting",  10, me, fighter, 0);

	return 1;
}

int fighting(object me, object fighter, int count)
{
	object monk1, monk2, room1, room2;
	object book;

	if(!( room1 = find_object("/d/tianlongsi/munitang")) )
	room1 = load_object("/d/tianlongsi/munitang");

	if(!( room2 = find_object("/d/tianlongsi/banruotai")) )
	room2 = load_object("/d/tianlongsi/banruotai");

	if( count <= 4 ) {
		message("vision", HIM"\n六脉剑阵剑气纵横，紫蕴斜飞！\n" NOR, room2);

		monk1 = present(names[count], room1);
		monk1->move(room2);
	}
		
	if( count >= 1 && count <= 5 ) {
		monk2 = present(names[count-1], room2);
		monk2->move(room1);
	}

	if( !find_player(me->query("assigned_fighter")) ||
	!living(fighter) || fighter->query("qi") <= 1 )
	{
		if( objectp(present(me->query("assigned_fighter"), environment(me)) )) {
			fighter->delete_temp("fighting");
			fighter->delete_temp("beat_count");
		}
		monk1->move(room1);

		say( "枯荣大师摇了摇头，说道：火候还差 ... 唉！\n\n");
		fighter->delete_temp("fighting");
		command("sigh");
		call_out("do_back", 2, me );
	}
	else if( count >= 5 )
	{
		if( (int)fighter->query_temp("beat_count") >= 5 )	
		{
			call_out("do_recruit", 2, me, fighter);
		}
		else
			call_out("do_back", 2, me );
	}
	else
	{
		count++;
		call_out("fighting", 2, me, fighter, count);
	}
 
	return 1;
}

int do_recruit(object me, object fighter)
{
	object book;
	mapping ft_fam, my_fam;

	fighter->delete_temp("beat_count");
	fighter->delete_temp("fighting");
	command("say 再接我一招！");
	COMBAT_D->do_attack(this_object(), fighter, query_temp("weapon") );
	if( !living(fighter) || fighter->query("qi") <= 1 )
		say("\n枯荣大师说道：还是不行！ \n");
	else
	{
		say("\n枯荣大师说道：恭喜你闯过了六脉剑阵！ \n");
		if (query("book_count") > 0)
		{
			add("book_count", -1);
			book = new("/clone/book/six_book");
			book->move(fighter);
//		command("rumor "+fighter->query("name")+"拿到啦。\n");
			message("channel:rumor", MAG"【谣言】某人："+fighter->query("name")+"抢了六脉神剑谱啦。\n"NOR, users());
			command("say 好吧，这本「六脉神剑谱」你就拿去吧。说着惨然一笑。\n");
		}
		else
			command("say 「六脉神剑谱」已经不在我这了。施主请便。\n");
	}
	call_out("do_back", 5, me );
		
	return 1;
}

int do_back(object me)
{
        object monk, room1, room2;
	int i;

	message("vision", "\n枯荣大师挥了挥手，回身步入牟尼堂。\n", environment(me) );

	if(!( room1 = find_object("/d/tianlongsi/banruotai")) )
	room1 = load_object("/d/tianlongsi/banruotai");
	room1->set("exits/north", "/d/tianlongsi/doushuai" );
	room1->set("exits/south", "/d/tianlongsi/munitang");

	if(!( room1 = find_object("/d/tianlongsi/baodian")) )
	room1 = load_object("/d/tianlongsi/baodian");

	if(!( room2 = find_object("/d/tianlongsi/munitang")) )
		room2 = load_object("/d/tianlongsi/munitang");

	if( objectp( monk = present("ben yin", room2) ));
		monk->move(room1);

	me->delete("assigned_fighter");
	this_object()->move("/d/tianlongsi/munitang");
	return 1;
}

string ask_join()
{
	object me;

	me = this_player();

	if( (string)me->query("class")=="bonze" )
		return "阿弥陀佛！你我同是出家人，何故跟贫僧开这等玩笑？\n";

	if( (string)me->query("gender") != "男性" )
		return "阿弥陀佛！善哉！善哉！女施主若真心皈依我佛，可去后山庵里受戒。\n";

	me->set_temp("pending/join_bonze", 1);
	return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下(kneel)受戒。\n";
}

int do_kneel()
{
	object me = this_player();

	string name, new_name;

	if( !me->query_temp("pending/join_bonze") )
		return 0;

	message_vision(
		"$N双手合十，恭恭敬敬地跪了下来。\n\n"
		"$n说偈道：
        “一微尘中入三昧，成就一切微尘定，
          而彼微尘亦不增，于一普现难思刹。”
手掌提起，$N满头乌发尽数落下，头顶光秃秃地更无一根头发，便是
用剃刀来剃亦无这等干净。\n\n",
		me, this_object() );
	name = me->query("name");
	new_name = "本" + name[0..1];
	command("say 从今以后你的法名叫做" + new_name + "。");
	command("smile");
	me->delete_temp("pending/join_bonze");
	me->set("name", new_name);
	me->set("class", "bonze");
	me->set("K_record", me->query("PKS") + me->query("MKS"));
	me->set("shen_record", me->query("shen"));
        me->set("shen", 0);

	return 1;
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "男性" )
	{
		command ("say 阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。");
		return;
	}
	if( (string)ob->query("class")!="bonze" )
	{
		command ("say 阿弥陀佛！贫僧不收『俗家弟子』。");
		return;
	}
        if ((int)ob->query_skill("kurong-changong", 1) < 150) {
                command("say 你内功修为还不到火候，进天龙寺也是徒劳。\n");
                return;
        }
	command("say 阿弥陀佛，善哉！善哉！");
	command("recruit " + ob->query("id"));
}

