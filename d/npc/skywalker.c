// 天马行空
#include <ansi.h>

inherit NPC;

string *rnd_say = ({
        "我天马行空，是名震天下的大英雄，历来好交朋友。这里的人居然都不理我！",
        "为什麽司马箐箐这小姑娘还没来？又和那个小王八蛋在一起鬼混了？",
        "有谁可以给我一些钱？无情的一千两银子还我的时候我再还给你吧！",
        "我想看看天雕的屁股向后平沙落雁式！",
        "澄天这个老秃驴在这里还不是方丈？真可怜．．．",
        "那个死木森林牛鼻子为什么不来接我们？",
        "晓旭这个小混蛋在哪里？",
        "厦门的美眉听说很漂亮？",
        "快打酒来！愣什么！",
        "快把大宝和二宝拉成一堆烂肉！",
        "老老就是伪君子．．．",
        "你是狐尾猫？",
        "嗨..",
});

void greeting(object ob);
void stealing(object ob);
varargs void drool(string msg, string who);

void create()
{
        string name, id;

        set_name("天马行空", ({ "skywalker" }) );
        set("title", "普通百姓");
        set("gender", "男性");
        set("age", 14);
        set("attitude", "friendly");
        set("combat_exp", 10000000);
        set("env/wimpy", 100);
        set("chat_chance", 200);
        set_skill("stealing", 300);
	set("str", 85);
	set("con", 85);
	set("int", 85);
	set("dex", 85);
	set("kar", 100);
	set("max_qi", 5000);
	set("max_jing", 2000);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("shen_type", 0);
	set("thief", 0);
        set("chat_msg", ({
                "我天马行空，是名震天下的大英雄，历来好交朋友。这里的人居然都不理我！\n",
                "厦门的美眉听说很漂亮？\n",
                "快打酒来！愣什么！\n",
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );
        setup();
	carry_object("/clone/misc/cloth")->wear();
        if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}

int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "？", "");
        msg = replace_string(msg, "？", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "！", "");
        msg = replace_string(msg, "啊", "");
        msg = replace_string(msg, "吗", "");
        msg = replace_string(msg, "耶", "");
        msg = replace_string(msg, "吧", "");

        if( msg!="" ) {
                add("memory/" + who, ({ msg }));
                return 1;
        } else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
        string who, phrase;

        if( !userp(ob) || (channel != "chat") ) return;
        who = ob->query("name");

        // Don't process our own speech.
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
        string who, phrase;

//        if( !userp(ob) ) return;
        who = ob->query("name");

        // Don't process our own speech
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) && random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) {
        case "poke":
                command("poke skywalker");
                break;
        case "sorry":
        case "thank":
        case "admire":
        case "thumb":
        case "u&me":
        case "slapsb":
        case "rich":
        case "handsome":
                if( random(10)<5 )
                      command("hehe");
                else
                      command("nali " + ob->query("id"));
                break;
        case "u&me2":
        case "aunt":
        case "visit":
        case "sister":
        case "brother":
        case "bow":
                if( random(10)<5 )
                      command("hehe");
                else
                      command("shy");
                break;
        case "gongxi":
                command("tongxi " + ob->query("id"));
                break;
        case "sigh":
        case "poor":
                if( random(10)<5 )
                      command("say 为什麽叹气？");
                else
                      command("laugh " + ob->query("id"));
                break;
        case "kick":
        case "kick1":
        case "kick2":
        case "foot":
        case "pai":
                if( random(10)<5 )
                      command("say 为什麽踢我？会痛耶！");
                else
                      command(verb + " " + ob->query("id"));
                break;
        case "wake":
        case "pig":
        case "zhu":
                if( random(10)<5 )
                      command("say 你才是猪呢！");
                else
                      command(verb + " " + ob->query("id"));
                break;
        case "shout":
        case "grin":
        case "xixi":
        case "hehe":
        case "heihei":
        case "laugh":
        case "sneer":
        case "heng":
        case "story":
        case "smirk":
        case "sing":
        case "sing2":
        case "sing3":
        case "yehua":
                if( random(10)<5 )
                      command("say 才睡着就给你吵醒了！");
                else
                      command("seal");
                break;
        case "slap":
        case "club":
        case "hammer":
        case "hammer1":
        case "hammer2":
        case "maimai":
                if( random(10)<5 )
                      command("say 为什麽打我？会痛耶！");
                else
                      command(verb + " " + ob->query("id"));
                break;
        default:
                if( random(10)<5 )
                      command(verb + " " + ob->query("id"));
                else
                      command("waggle " + ob->query("id"));
        }
}

varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob;
        string mrh;

        mem = query("memory");
        if( !mapp(mem) ) return;

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }
        mrh="";

        if( strsrch(msg, "混蛋") >=0 ) mrh="小混蛋";
        else if( strsrch(msg, "浑蛋") >=0 ) mrh="大浑蛋";
        else if( strsrch(msg, "鸟") >=0 ) mrh="小鸟人";
        else if( strsrch(msg, "八婆") >=0 ) mrh="三八婆";
        else if( strsrch(msg, "坏蛋") >=0 ) mrh="大坏蛋";
        else if( strsrch(msg, "王八") >=0 ) mrh="小王八";
        else if( strsrch(msg, "驴") >=0 ) mrh="笨驴子";
        else if( strsrch(msg, "土人") >=0 ) mrh="小土人";
        else if( strsrch(msg, "土鳖") >=0 ) mrh="大土鳖";
        else if( strsrch(msg, "兔崽子") >=0 ) mrh="小兔崽子";
        else if( strsrch(msg, "流氓") >=0 ) mrh="大流氓";
        else if( strsrch(msg, "反动") >=0 ) mrh="反动派";
        else if( strsrch(msg, "地主") >=0 ) mrh="小地主";
        else if( strsrch(msg, "妓女") >=0 ) mrh="小妓女";
        else if( strsrch(msg, "龟公") >=0 ) mrh="小龟公";
        if (mrh!="") {
              switch(random(20)) {
              case 0: command("say " + who + "是在说自己吗？"); break;
              case 1: command("say " + who + "在说自己是" + mrh + "！"); break;
              case 2: command("kick2 " + who); break;
              case 3: command("slap " + who); break;
              case 4: command("hammer " + who); break;
              case 5: command("taunt " + who); break;
              case 6: command("rascal " + who); break;
              case 7: command("grin " + who); break;
              case 8: command("slogan " + who); break;
              case 9: command("kick1 " + who); break;
              case 10: command("foot " + who); break;
              case 11: command("maimai " + who); break;
              case 12: command("pai " + who); break;
              default: command("say 我们开始讨论有关" + who + "是" + mrh + "的话题好吗？");
              }
        }
        else if( (strsrch(msg, "为什麽") >= 0) ) {
                if( sscanf(msg, "%*s为什麽%s", msg)==2 ) msg = "为什麽" + msg;
                switch(random(20)) {
                case 0: command("say " + who + "，你是在问我吗？"); break;
                case 1: command("say 关於" + msg + " ... "); break;
                case 2: command("say 呃 ... "); drool(); break;
                case 3: command("say 这个问题嘛 ...."); break;
                case 4: command("say " + who + "，知道这个问题的答案对你那麽重要么？"); break;
                case 5: command("say " + msg + "？"); break;
                case 6: command("say " + who + "你能不能说清楚一点？"); break;
                case 7: command("say " + who + "，我不懂你问的问题"); break;
                case 8: command("say " + who + "，小王八蛋别乱问！"); break;
                default: command("? " + who ); break;
                }
        }
        else if( (strsrch(msg, "你") >= 0)
        ||      (strsrch(msg, "他") >= 0)
        ||      (strsrch(msg, "drooler") >= 0)
        ||      (strsrch(msg, "Drooler") >= 0)) {
                if( sscanf(msg, "%*s你%s", msg) == 2 ) msg = "你" + msg;
                msg = replace_string(msg, "你", "我");
                msg = replace_string(msg, "他", "我");
                switch(random(20)) {
                case 0: command("say " + who + "，你是说" + msg + "吗？");break;
                case 1: command("say 你确定" + msg + "？");     break;
                case 2: command("say " + msg + "跟你有什麽关系？");     break;
                case 3: command("say 嗯 ... " + who + "说得好"); break;
                case 4: command("say " + who + "你为什麽对" + msg + "这麽有兴趣？"); break;
                case 5: command("say 为什麽你认为" + msg + "？"); break;
                case 6: command("say 换个话题吧"); drool(); break;
                case 7: command("say 才怪"); break;
                case 8: command("say 不一定吧？"); break;
                default: command("say 有这个可能 ...."); break;
                }
        }
        else if( (strsrch(msg, "我") >= 0)) {
                if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
                msg = replace_string(msg, "我", "你");
                msg = replace_string(msg, "?", "");
                switch(random(20)) {
                case 0: command("say 你是说" + msg + "吗？"); break;
                case 1: command("say 真的？" + msg + "？");     break;
                case 2: command("say 如果" + msg + "，我能帮你什麽忙吗？");break
;
                case 3: command("hmm"); break;
                case 4: command("say 你认为" + msg + "？"); break;
                case 5: command("say 我有同感"); break;
                case 6: command("say 你说的「" + msg + "」我不能苟同"); break;
                default: command("say 有关「" + msg + "」的话题到此为止好吗？");break;
                }
        } else {
                switch(random(20)) {
                        case 0: command("say 为什麽说" + msg + "?"); break;
                        case 1: command("say 「" + msg + "」是什麽意思？"); break;
                        case 2: command("say " + msg + "？"); break;
                        case 3: command("grin"); break;
                        case 4: command("smile"); break;
                        case 5: command("?"); break;
                        case 6: command("say ...."); break;
                        case 7: command("hmm"); break;
                        case 8: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
                        case 9: command("say 你怎麽知道" + msg + "?"); break;
                        case 10: command("say 刚刚" + who + "不是说了，" + msg);
                        case 11: command("say 我当然知道，" + msg); break;
                        case 12: command("say 然後呢？"); break;
                        case 13: command("say 真的吗？"); break;
                        case 14: command("say 我不这麽认为。"); break;
                        default: command("say 我可不知道。"); break;
                }
        }
}

void reset()
{
        delete("memory");
}

int accept_object()
{
        return 1;
}
void init()
{
    object ob;

    ::init();
    if( interactive(ob = this_player()) && !is_fighting() ) {
//         remove_call_out("stealing");
//         call_out("stealing", 5, ob);
         stealing(ob);
         remove_call_out("greeting");
         call_out("greeting", 1, ob);
    }
    add_action("do_dajia","hit");
    add_action("do_kill","kill");
    add_action("do_dajia","fight");
}

void greeting(object ob)
{
    if ( !ob || environment(ob) != environment() )
          return;
    say( "天马行空终于看到一位酒友，急忙喊到：快过来和兄弟我喝酒！\n");
    if (!wizardp(ob))
    {
          message_vision("天马行空冲着$N挤挤鬼脸，一串串酒嗝冲着$N直冒。\n",ob,ob);
          ob->apply_condition("drunk", 20);
    }
}

void stealing(object ob)
{
      mapping fam; 
 
      if( !ob || environment(ob) != environment() || ob->query_int() > 30 )
            return;

      switch( random(3) ) {
            case 0:
                  command("hehe " + ob->query("id"));
                  command("steal coin from " + ob->query("id"));
                  break;
            case 1:
                  command("grin " + ob->query("id"));
                  command("steal silver from " + ob->query("id"));                  
                  break;
            case 2:
                  command("hi " + ob->query("id"));
                  command("steal gold from " + ob->query("id"));                  
                  break;
      }
}

int do_dajia()
{
    object ob;

    ob = this_player();
    message_vision("天马行空提起老拳将$N一顿臭打！\n",ob);
    message_vision("$N躺在地上，大叫＂天马行空爷爷，大英雄饶命！＂天马行空一张\n",ob);
    message_vision("脸顿时露出笑容：＂$N有眼光，还算是个好人，收手不打了！\n",ob);
    ob -> set("qi",10);
    return 1;
}

int do_kill()
{
    object ob;
    ob = this_player();
    message_vision("天马行空提起老拳将$N往死里打！两手抓住\n",ob);
    message_vision("$N双脚，嘿地一声低喝，只听得一声惨呼，满地鲜血内脏\n",ob);
    message_vision("$N竟被活生生撕成两片，动作实在是太快了，别人都救护不了！\n",ob);
    ob->die();
    return 1;
}

