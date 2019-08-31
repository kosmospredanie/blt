#ifndef __BLT_COLLISIONS_H__
#define __BLT_COLLISIONS_H__

#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "math.hpp"
#include "node.hpp"

using namespace std;
using namespace sf;

namespace blt {
	enum CollidableType {
		CIRCLE,
		RECT
	};

	/**
	 * @note The transform of the node affects only the position of the
	 * Collidable and not the others -- scale, rotation, etc.
	 */
	class Collidable {
	public:
		Collidable ();
		virtual ~Collidable ();
		virtual CollidableType getType () const = 0;
		const Node *getNode () const;
		/**
		 * @note This Collidable doesn't hold the ownership of the given node.
		 */
		void setNode (const Node &node);
		virtual bool collideWith (const Collidable &other) const = 0;
		/**
		 * Gets the bounds in the given coordinates.
		 *
		 * @param[in] coordinates The coordinates
		 * @return The bounds in the given coordinates
		 */
		virtual FloatRect getBounds (const Node *coordinates) const = 0;
	private:
		const Node *_node;
	};

	class CircleCollidable : public Collidable {
	public:
		CircleCollidable (const Circle &circle);
		virtual ~CircleCollidable () override;
		virtual CollidableType getType () const override;
		virtual bool collideWith (const Collidable &other) const override;
		virtual FloatRect getBounds (const Node *coordinates) const override;
		const Circle &getCircle () const;
		/**
		 * Gets the circle in the given coordinates.
		 *
		 * @param[in] coordinates The coordinates
		 * @return The circle in the given coordinates
		 */
		Circle getCoordinatedCircle (const Node *coordinates) const;
	private:
		Circle _circle;
	};

	class RectCollidable : public Collidable {
	public:
		RectCollidable (const FloatRect &rect);
		virtual ~RectCollidable () override;
		virtual CollidableType getType () const override;
		virtual bool collideWith (const Collidable &other) const override;
		virtual FloatRect getBounds (const Node *coordinates) const override;
		const FloatRect &getRect () const;
	private:
		FloatRect _rect;
	};
}

#endif
