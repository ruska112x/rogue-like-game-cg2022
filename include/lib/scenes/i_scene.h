#ifndef INCLUDE_LIB_SCENES_I_SCENE_H_
#define INCLUDE_LIB_SCENES_I_SCENE_H_

#include "lib/scenes/context.h"

/**
 * Базовый интерфейс для всех сцен в игре.
 * Владеет экземпляром этого класса SceneManager.
 * SceneManager НЕ отвечает за создание сцен.
 * SceneManager ОТВЕЧАЕТ за удаление сцен из памяти.
 *
 * Сцена создается ОДИН раз на всё приложение.
 */
class IScene {
 protected:
  Context* const ctx_;

 public:
  bool is_created_ = false;
  /**
   * Все сцены обязаны принимать на вход и зхранить указатель на Context.
   * @param ctx В контексте хранится информация о сцене, которую нужно сейчас отрисоватывать.
   */
  explicit IScene(Context* const ctx) : ctx_(ctx) {}
  /**
   * Деструктор сцены. Вызывается когда всё приложение выключается.
   * Проверьте, что вы уничтожаете все объекты, которыми владеете.
   */
  virtual ~IScene() = default;

  /**
   * Эта функция запускается один раз, когда произошел переход на эту сцену.
   * В следующий раз эта функция запустится при очередном переходе на эту сцену.
   */
  virtual void OnCreate() = 0;
  /**
   * Эта функция запускается на каждый тик игрового цикла.
   */
  virtual void OnRender() = 0;
  /**
   * Эта функция запускается один раз при переходе с этой сцены на какую-то другую.
   * В следующий раз эта функция запустится при очередном переходе на эту сцену.
   */
  virtual void OnExit() = 0;
};

#endif  // INCLUDE_LIB_SCENES_I_SCENE_H_
